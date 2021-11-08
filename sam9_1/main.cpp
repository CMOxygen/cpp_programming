#include <iostream>

using namespace std;

/*  Написать клаас, в котором должен быть механизм ,который отслеживает количество
 *  существующих объектов класса. ПРедусмотреть некоторые механизмы внутри деструктора и
 *  деструктора, которые при появлении объекта.
 */

class A
{

private:
    static int objectsCount;

public:
    A();
    ~A();

    static void displayObjectsCount() { cout << "class has " << objectsCount << " objects" << endl; }
};

A::A()
{
    objectsCount++;
}

A::~A()
{
    if (objectsCount > 0)
        objectsCount--;
}

int A::objectsCount = 0;

int main(int argc, char **argv)
{
    // A arr[10];
    A *arr = new A[10];

    A::displayObjectsCount();

    for (int i = 0; i < 10; i++)
    {
        delete &arr[i];
        A::displayObjectsCount();
    }
}