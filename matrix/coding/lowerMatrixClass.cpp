#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();

    ~Matrix() { delete[] A; }
};

void Matrix::set(int i, int j, int x)
{
    if (i >= j)
        A[(n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j)] = x;

    else
        A[(n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j)] = 0;
}

int Matrix::get(int i, int j)
{
    if (i >= j)
        return A[(n * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j)];
    else
        return 0;
}

void Matrix::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix m(4);
    m.set(1, 1, 1);
    m.set(2, 1, 2);
    m.set(2, 2, 3);
    m.set(3, 1, 4);
    m.set(3, 2, 5);
    m.set(3, 3, 6);
    m.set(4, 1, 7);
    m.set(4, 1, 7);
    m.set(4, 2, 8);
    m.set(4, 3, 9);
    m.set(4, 4, 10);
    m.display();
}