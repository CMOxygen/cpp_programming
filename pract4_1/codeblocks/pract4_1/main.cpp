#include <iostream>

using namespace std;

// inline void test() { cout << "inline test" << endl; }

int main(int argc, char **arg)
{
    // test();

    int x = 10;
    cout << "x = " << x << "    &x = " << &x << endl;

    int y = 20;
    cout << "y = " << y << "    &y = " << &y << endl;

    int *pA = nullptr;
    pA = new int(5);
    // *pA = 5;

    cout << "*pA = " << *pA << "    pB = " << pA << endl;

    double *pB = new double(64.5);
    cout << "*pB = " << *pB << "    pB = " << pB << endl;

    const int K = 5;

    int *Mas = new int[K];

    for (int i = 0; i < K; i++)
        Mas[i] = (i + 1) * 10;

    for (int i = 0; i < K; i++)
        cout << "   Mas[" << i << "]= " << Mas[i] << endl;

    cout << endl;

    delete pA;
    delete pB;
    delete[] Mas;

    for (int i = 0; i < K; i++)
        cout << "   Mas[" << i << "]= " << Mas[i] << endl;

    cout << endl;

    pA = nullptr;
    pB = nullptr;
    Mas = nullptr;

    cout << Mas[2] << endl;

    for (int i = 0; i < K; i++)
        cout << "   Mas[" << i << "]= " << Mas[i] << endl;
}
