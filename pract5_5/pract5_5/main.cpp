#include <iostream>

using namespace std;

class A
{
private:
    int xa = 0;

public:
    A(){cout << "constructor A" << endl;};
    A(int x){cout << "constructor A, x = " << x << endl; this->xa = x; };
    ~A(){cout << "destructor A" << endl;};
};

class B : public A
{
private:
    int xb = 0;

public:
    B(){cout << "constructor B" << endl;};
    ~B(){cout << "destructor B" << endl;};
    B(int x,int y) : A(y){cout << "constructor B, x = " << x << endl; this->xb = x; };
};

int main()
{
    B b(2,3);
}
