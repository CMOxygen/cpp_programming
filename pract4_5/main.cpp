#include <iostream>

using namespace std;

class A;
class B;
class C;
class D;
class E;

class A
{
public:
    void test() { cout << "Testing" << endl; }
};

class B : public A
{
};

class C : public B
{
};

class D
{
public:
    void testD() { cout << "TestingD" << endl; }
};

class E : public A, public D
{
};

int main(int argc, char **argv)
{
    A a;
    a.test();

    D d;
    d.testD();

    E e;
    e.test();
    e.testD();

    return 0;
}