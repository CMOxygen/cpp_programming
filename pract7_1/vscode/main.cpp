#include <iostream>

using namespace std;

const int K = 10;

/* 
Использование встренного прсвоения оператора по умолчанию может привести к некорректной работе объектов,
использующих внешний ресурс.
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
    cout << "Array1 :" << endl;
    DinArr dinarr1(1);
    dinarr1.show();

    cout << "Array2 :" << endl;
    DinArr dinarr2(3);
    dinarr2.show();

    cout << " Array3 :" << endl;
    DinArr dinarr3(5);
    dinarr3.show();
}