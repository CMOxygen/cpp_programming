#include <iostream>

using namespace std;

class A
{

private:
    int x = 0;
    static int y;

public:
    A();
    ~A();

    void displayX() { cout << "x = " << x << endl; }
    void displayY() { cout << "y = " << y << endl; }
    void setX(int i) { x = i; }
    void setY(int i) { y = i; }
};

A::A()
{
}

A::~A() {}

int A::y;

int main(int argc, char **argv)
{
    A a1;

    a1.setX(1);
    a1.setY(2);
    a1.displayX();
    a1.displayY();

    a1.setX(2);
    a1.setY(20);
    a1.displayX();
    a1.displayY();

    A a2;
    a2.displayX();
    a2.displayY();

    cout << A::y << endl;
}