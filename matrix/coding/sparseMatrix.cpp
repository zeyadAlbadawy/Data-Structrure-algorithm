#include <iostream>
using namespace std;

struct element
{
    int i;
    int j;
    int x;
};

struct sparse
{
    int m;
    int n;
    int numOfNonZero;
    struct element *ele;
};

void createFunc(struct sparse *s)
{
    cout << "Enter The Dimentions" << endl;
    cin >> s->m >> s->n;

    cout << "Enter No.Of Non-Zero Elements" << endl;
    cin >> s->numOfNonZero;
    s->ele = new element[s->numOfNonZero];

    cout << "Enter Non-Zero Elemnts " << endl;
    for (int i = 0; i < s->numOfNonZero; i++)
    {
        cin >> s->ele[i].i;
        cin >> s->ele[i].j;
        cin >> s->ele[i].x;
    }
}

void display(struct sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
                cout << s.ele[k++].x << " ";
            else
                cout << "0 ";
        }

        cout << endl;
    }
}

struct sparse *add(struct sparse *s1, struct sparse *s2)
{
    int i = 0, j = 0, k = 0;
    struct sparse *sum;
    sum = new sparse;
    sum->ele = new element[s1->numOfNonZero + s2->numOfNonZero];

    if (s1->m != s2->m || s1->n != s2->n)
        return 0;

    while (i < s1->numOfNonZero && j < s2->numOfNonZero)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s2->ele[j].i < s1->ele[i].i)
            sum->ele[k++] = s2->ele[j++];
        else if (s1->ele[i].i == s2->ele[j].i)
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s2->ele[j].j < s1->ele[i].j)
                sum->ele[k++] = s2->ele[j++];
            else if (s1->ele[i].j == s2->ele[j].j)
            {
                sum->ele[k].i = s1->ele[i].i;
                sum->ele[k].j = s1->ele[i].j;
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }

    for (; i < s1->numOfNonZero; i++)
        sum->ele[k++] = s1->ele[i++];
    for (; j < s2->numOfNonZero; j++)
        sum->ele[k++] = s2->ele[j++];
    sum->m = s1->m;
    sum->n = s2->n;
    sum->numOfNonZero = k;
}

int main()
{
    struct sparse s1, s2, *s3;
    createFunc(&s1);
    createFunc(&s2);
    s3 = add(&s1, &s2);

    cout << "The first Matrix is " << endl;
    display(s1);
    cout << "The Second Matrix is " << endl;
    display(s2);
    cout << "The Sum of S1 and S2 is " << endl;
    display(*s3);

    return 0;
}