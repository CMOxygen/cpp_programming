#include <iostream>

using namespace std;

void f1();
void f2();

int main(int argc, char **argv)
{
    for (int i = 0; i < 10; i++)
        f1();

    f2();

    f1();

    return 0;
}

void f1()
{
    int a = 0;
    static int b = 0;
    cout << "a = " << a << " b = " << b << endl;

    a++;
    b++;
    cout << "a = " << a << " b = " << b << endl;
    cout << endl;
}

void f2()
{
    static int b = 1;

    cout << "b f2 = " << b << endl;
    cout << endl;
}