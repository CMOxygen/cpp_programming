#include <iostream>

using namespace std;



class A
{
public:
    A();
    ~A();
};

class B
{
private:
    int z;

public:
    B(int value);
    ~B();

    int getZ(){ return z; }
    int setZ(int newValue) { z = newValue; }
};

B::B(int value)
{    setZ(value);
    cout << "constructor B" << endl;
}
B::~B()
{
    cout << "destructor B" << endl;
}
A::A()
{
    cout << "constructor A" << endl;
}
A::~A()
{
    cout << "destructor A" << endl;
}
int main()
{
    A objA;
    B objB(10);

    cout << "z = " << objB.getZ() << endl;

    return 0;
}
