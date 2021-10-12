#include <iostream>

using namespace std;

class A
{
private:
    int x = 0;

public:
    A(){cout << "constructor a" << endl;};
    A(int y){cout << "constructor A, x = " << y << endl; this->x = y; };
    ~A(){cout << "destructor a" << endl;};
};

class B
{
private:
    int x = 0;

public:
    B(){cout << "constructor b" << endl;};
    ~B(){cout << "destructor B" << endl;};

    B(int b){cout << "constructor B, x = " << x << endl; this->x = b;};

};

class C
{
private:
    int x = 0;

public:
    C(){cout << "constructor C" << endl;};
    ~C(){cout << "destructor C" << endl;};
    C(int y){cout << "constructor C, x = " << y << endl; this->x = y; };
};

class D : public C, public B, public A
{
private:
    int x = 0;

public:
    D(){cout << "constructor D" << endl;};
    ~D(){cout << "destructor D" << endl;};
    D(int a, int b, int c, int d): C(c), B(b), A(a){cout << "constructor D, x = " << x << endl; x = d;};


};

int main()
{
    D(1,2,3,4);
}
