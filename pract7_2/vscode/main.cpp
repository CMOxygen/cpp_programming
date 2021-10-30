#include <iostream>

using namespace std;

const int K = 10;

/* 
Использование встренного прсвоения оператора по умолчанию может привести к некорректной работе объектов,
использующих внешний ресурс.
*/

/*

*/

class DinArr
{
private:
    // int *arr = nullptr;
    // int size = 0;
    int *arr;
    int size;

public:
    DinArr(int x);
    DinArr();
    ~DinArr();

    void show();

    DinArr &operator=(const DinArr &ob);
    DinArr &operator=(int x);

    int operator[](int index) { return this->arr[index]; }
};

DinArr::DinArr(int x)
{
    size = K;
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
    if (this == &ob)
        return *this;

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
    DinArr dinarr1(1);
    cout << "Array1 :" << endl;
    dinarr1.show();

    DinArr dinarr2(3);
    cout << "Array2 :" << endl;
    dinarr2.show();

    dinarr2 = dinarr1;
    cout << " Array2 = Arra1 :" << endl;
    dinarr2.show();

    DinArr dinarr3(5);
    cout << "Array3 :" << endl;
    dinarr3.show();

    dinarr3 = 6;
    cout << "Array3 = 6 :" << endl;
    dinarr3.show();

    dinarr3 = dinarr2 = 7;

    cout << "Array3 = Array2 =  7 :" << endl;
    dinarr3.show();

    cout << "Array2 = Array3 =  7 :" << endl;
    dinarr2.show();

    cout << dinarr3[2] << endl;
}