#include <iostream>

using namespace std;

class A
{
private:
    int x = 0;
    int y = 0;

public:
   //explicit A();
    A();
    ~A();

    int getX(){ return this->x; }
    void setX(int newValue){ this->x = newValue; }

    int getY(){ return this->y; }
    void setY(int newValue){ this->y = newValue; }
};

A::A()
{
    cout << "constructor works!" << endl;
}

A::~A()
{
    cout << "destructor works!" << endl;
}

int main()
{
//    A *object = new A();

    A object;

 //   object->setX(5);
 //   object->setY(10);

    object.setX(5);
    object.setY(10);

//    cout << "object.x = " << object->getX() << endl;
//    cout << "object.y = " << object->getY() << endl;

    cout << "object.x = " << object.getX() << endl;
    cout << "object.y = " << object.getY() << endl;

    return 0;
}
