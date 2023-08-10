#include <iostream>
#include <stdio.h>

using namespace std;

struct Matrix
{
    int *A;
    int n;
};

void setFunc(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

int getFunc(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i >= j)
                cout << m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";
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
    cout << " Enter Size Of Matrix" << endl;
    cin >> m.n;
    m.A = (int *)malloc(((m.n * ((m.n) + 1)) / 2) * sizeof(int));
    int value = 0;
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i >= j)
            {
                cin >> value;
                m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = value;
            }
            else
                m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = 0;
        }
    }
    Display(m);
}