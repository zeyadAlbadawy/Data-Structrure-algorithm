#include <iostream>
using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

void setFunc(struct Matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}

int getFunc(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
                cout << m.A[i] << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}

int main()
{
    struct Matrix m;
    m.n = 4;
    setFunc(&m, 1, 1, 1);
    setFunc(&m, 2, 2, 2);
    setFunc(&m, 3, 3, 3);
    setFunc(&m, 4, 4, 4);

    Display(m);
}