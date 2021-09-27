#include <iostream>

using namespace std;

void createArray(int *&, int &);
void displayArray(const int *const, const int);

int main(int argc, char **argv)
{
    int *Mas = nullptr;
    int K = 0;

    createArray(Mas, K);
    displayArray(Mas, K);

    delete[] Mas;
    Mas = nullptr;
}

void createArray(int *&M, int &K)
{
    K = 5;
    M = new int[K];

    for (int i = 0; i < K; i++)
        M[i] = (i + 1) * (i + 2);

    cout << "Massiv:    " << endl;

    for (int i = 0; i < K; i++)
        cout << M[i] << "   ";

    cout << endl;
}

void displayArray(const int *const M, const int K)
{
    cout << "Massiv: " << endl;

    for (int i = 0; i < K; i++)
        cout << M[i] << "   ";
}