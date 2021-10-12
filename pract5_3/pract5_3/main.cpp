#include <iostream>

using namespace std;

class A
{
private:
    int xa = 0;
    int ya = 0;
public:
    A(){cout << "constructor a" << endl;};
    A(int y){cout << "constructor ya: " << y << endl; this->ya = y; };
    ~A(){cout << "destructor a" << endl;};

    void xaEnter(){cout << "xaEnter" << endl; this->xa = 30;}
    void xaDisplay(){cout << this->xa << endl;}
    void setXA(int a){this->xa = a;}
};

class B : public A
{
private:
    int xb = 0;
    int yb = 0;

public:
    B(){cout << "constructor b" << endl;};
    ~B(){cout << "destructor B" << endl;};
    B(int y) : A(y){cout << "constructor yb: " << y << endl; this->yb = y; };

    void xbEnter(){cout << "xbEnter" << endl; this->xb = 2;}
    void xbDisplay(){cout << this->xb << endl;}
};
class C
{
private:
    int xc = 0;
    int yc = 0;
public:
    C(){cout << "constructor C" << endl;};
    ~C(){cout << "destructor C" << endl;};
    C(int y){cout << "constructor yc: " << y << endl; this->yc = y; };

    void xcEnter(){cout << "xcEnter" << endl; this->xc = 4;}
    void xcDisplay(){cout << this->xc << endl;}
};

class D : public C, public B
{
    int xd = 0;
    int yd = 0;
public:
    D(){cout << "constructor D" << endl;};
    ~D(){cout << "destructor D" << endl;};
    D(int y) : B(y), C(y + 1){cout << "constructor yd: " << y << endl; this->yd = y;};
    void xdEnter(){cout << "xdEnter" << endl;  this->xd = 34;}
    void xdDisplay(){cout << this->xd << endl;}
    void xaEnter(){cout << "xaEnter66" << endl;  A::setXA(66);}
};

int main()
{
//    D d;
//
//    d.xaEnter();
//    d.xaDisplay();
//
//    d.xbEnter();
//    d.xbDisplay();
//
//    d.xcEnter();
//    d.xcDisplay();
//
//    d.xdEnter();
//    d.xdDisplay();

    D d2(5);

    d2.xaEnter();
    d2.xaDisplay();

    d2.xbEnter();
    d2.xbDisplay();

    d2.xcEnter();
    d2.xcDisplay();

    d2.xdEnter();
    d2.xdDisplay();

    return 0;
}
