#include <iostream>

using namespace std;

void f1(const int *const M, const int K)
{
    for(int i = 0; i < K; i++)
        cout << " " << M[i];

    cout<<endl;
}

int main()
{
    const int K = 3;
    int Mas[K] = {10,20,30};

    cout << "Array Address:"<< endl;
    f1(Mas, K);

    for(int i = 0; i < K; i++)
        cout << " " << Mas[i];

    cout<<endl;

    return 0;
}
