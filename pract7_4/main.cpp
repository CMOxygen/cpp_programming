#include <iostream>

/*
добавить в классы из предыдущего задания копирование и присвоение, конструктор копирования.
*/

using namespace std;

class DinArr
{
private:
    double *arr;
    int size;

public:
    DinArr(const DinArr &ob); //конструктор копирования
    DinArr(int K, double x, double y);
    ~DinArr();

    void show();
    void recreateArray();

    DinArr &operator=(const DinArr &ob);
};

DinArr::DinArr(const DinArr &ob)
{
    if (ob.arr == nullptr)
    {
        this->arr = nullptr;
        this->size = 0;
        return;
    }

    this->size = ob.size;
    this->arr = new double[size];

    for (int i = 0; i < size; i++)
        this->arr[i] = ob.arr[i];

    cout << "COPY CONSTRUCTOR WORKS" << endl;
}

DinArr::DinArr(int K, double x, double y)
{
    cout << "CONSTRUCTOR(int, double, double) WORKS" << endl;

    if (K <= 0)
    {
        cout << "arrSize is <= 0" << endl;
        arr = nullptr;
        size = 0;
        return;
    }
    else
    {
        size = K;
        arr = new double[size];

        for (int i = 0; i < size; i++)
            arr[i] = (x - i) * (x + 1) + y * y;
    }
}

DinArr::~DinArr()
{
    delete[] arr;
    arr = nullptr;
    cout << "DESTRUCTOR WORKS" << endl;
}

void DinArr::recreateArray()
{
    if (this->arr != nullptr)
    {
        cout << "Array already exists" << endl;

        for (int i = 0; i < this->size; i++)
        {
            cout << " " << this->arr[i] << endl;
        }
        cout << "\nType 1 to recreate" << endl;
        cout << "NO - 0" << endl;

        int f;

        cin >> f;

        if (f == 0)
            return;

        cout << "Enter size of array" << endl;
        cin >> this->size;

        delete[] this->arr;
        this->arr = new double[this->size];

        cout << "Enter double values" << endl;

        for (int i = 0; i < this->size; i++)
        {
            cout << "arr[" << i << "] = " << endl;
            cin >> this->arr[i];
        }
    }
}

DinArr &DinArr::operator=(const DinArr &ob)
{
    if (this == &ob && ob.size <= 0)
        return *this;

    delete[] this->arr;

    if (ob.arr == nullptr)
    {
        this->arr = nullptr;
        this->size = 0;
        return *this;
    }

    this->size = ob.size;

    for (int i = 0; i < size; i++)
        this->arr[i] = ob.arr[i];

    cout << "OPERATOR = (DinArr)" << endl;

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
    DinArr ob1(6, 4.5, 7.3);
    ob1.show();
    ob1.recreateArray();
    ob1.show();

    DinArr ob2(0, 0, 0);
    ob2.show();
    ob2.recreateArray();
    ob2.show();

    DinArr ob3(ob1);
    ob3.show();

    DinArr ob4 = ob2;

    ob4.show();
    ob4 = ob3;
    ob4.show();
}