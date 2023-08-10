#include <iostream>
using namespace std;

struct Term
{
    int coff;
    int pow;
};

struct poly
{
    int n;
    struct Term *term;
};

void create(struct poly *p)
{
    cout << "Enter the size of polynomail " << endl;
    cin >> p->n;
    p->term = new Term[p->n];
    cout << "Enter the Elements , First coff Second power " << endl;
    for (int i = 0; i < p->n; i++)
        cin >> p->term[i].coff >> p->term[i].pow;
}

void display(struct poly p)
{
    for (int i = 0; i < p.n; i++)
        if (i + 1 == p.n)
            cout << p.term[i].coff << "X" << p.term[i].pow;
        else
            cout << p.term[i].coff << "X" << p.term[i].pow << "+";
}

struct poly *add(struct poly *p1, struct poly *p2)
{
    struct poly *sum;
    sum = new poly;
    sum->term = new Term[p1->n + p2->n];
    int i, j, k;
    i = j = k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->term[i].pow > p2->term[j].pow)
            sum->term[k++] = p1->term[i++];
        else if (p2->term[j].pow > p1->term[i].pow)
            sum->term[k++] = p2->term[j++];
        else if (p1->term[i].pow == p2->term[j].pow)
        {
            sum->term[k].pow = p1->term[i].pow;
            sum->term[k++].coff = p1->term[i++].coff + p2->term[j++].coff;
        }
    }

    for (; i < p1->n; i++)
        sum->term[k++] = p1->term[i];
    for (; j < p2->n; j++)
        sum->term[k++] = p2->term[j];
    sum->n = k;
    return sum;
}

int main()
{
    struct poly p1, p2, *sum;
    create(&p1);
    create(&p2);
    sum = add(&p1, &p2);
    display(*sum);
}