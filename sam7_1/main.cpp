#include <iostream>

using namespace std;

/* 
Использование встренного прсвоения оператора по умолчанию может привести к некорректной работе объектов,
использующих внешний ресурс.
*/

class DinArr
{
private:
    int *arr;
    int size;

public:
    DinArr(int newSize, int x);
    DinArr();
    ~DinArr();

    void show();

    int getSize() { return this->size; }

    DinArr &operator=(const DinArr &ob);
    DinArr &operator=(int x);

    int operator[](int index) { return this->arr[index]; }
};

DinArr::DinArr(int newSize, int x)
{
    size = newSize;
    arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = x;

    cout << "CONSTRUCTOR WORKS" << endl;
}

DinArr::DinArr()
{
}

DinArr::~DinArr()
{
    delete[] arr;
    arr = nullptr;
    cout << "DESTRUCTOR WORKS" << endl;
}

DinArr &DinArr::operator=(const DinArr &ob)
{
    if (this == &ob && ob.size <= 0)
        return *this;

    this->size = ob.size;

    for (int i = 0; i < size; i++)
        this->arr[i] = ob.arr[i];

    cout << "OPERATOR = (DinArr)" << endl;

    return *this;
}

DinArr &DinArr::operator=(int x)
{
    for (int i = 0; i < size; i++)
        this->arr[i] = x;

    cout << "OPERATOR = (int)" << endl;

    return *this;
}

void DinArr::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << "   " << arr[i];
    }
    cout << "\nAddress of array beginning " << arr << endl;
}

int main(int argc, char **argv)
{
    DinArr dinarr1(5, 1);
    dinarr1.show();

    DinArr dinarr2(7, 3);
    cout << "Array2 size " << dinarr2.getSize() << ":" << endl;
    dinarr2.show();

    dinarr2 = dinarr1;
    cout << " Array2 = Arra1 :" << endl;
    dinarr2.show();

    DinArr dinarr3(9, 5);
    cout << "Array3 size " << dinarr3.getSize() << ":" << endl;
    dinarr3.show();

    dinarr3 = 6;
    cout << "Array3 = 6 :" << endl;
    dinarr3.show();

    dinarr3 = dinarr2 = 7;

    cout << "Array3 = Array2 =  7 :" << endl;
    dinarr3.show();

    cout << "Array2 = Array3 =  7 :" << endl;
    dinarr2.show();

    for (int i = 0; i < dinarr3.getSize() && i < dinarr1.getSize(); i++)
        cout << dinarr1[i] << " " << dinarr3[i] << endl;
}