#include <iostream>

/*
Написать два класса:
    1 класс реализует массив вещественных чисел. 
    2 класс реализует массив целых чисел.

    для каждого из них метод вывода массива на экран.
    дружественная функция, которая находит и выводит на экран наименьшй элемент из этих двух
    массивов.
*/

using namespace std;

class A;
class B;

class A
{
private:
    static const int size{10};
    int arr[size];

public:
    A() : arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} {}
    friend void findMin(const A &ob1, const B &ob2);
    void display();
};

class B
{
private:
    static const int size{6};
    int arr[size];

public:
    B() : arr{2, 4, 6, 8, 10, 12} {}
    friend void findMin(const A &ob1, const B &ob2);
    void display();
};

void findMin(const A &ob1, const B &ob2)
{
    const int theSize = ob1.size + ob2.size;

    int arrayToDisplay[theSize];
    int buff;

    int min = 100000;

    int j = 0;

    for (int i = 0; i < ob1.size; i++)
    {
        arrayToDisplay[j++] = ob1.arr[i];
    }
    for (int i = 0; i < ob2.size; i++)
    {
        arrayToDisplay[j++] = ob2.arr[i];
    }

    for (int i = 0; i < theSize; i++)
    {
        if (arrayToDisplay[i] < min)
        {
            min = arrayToDisplay[i];
        }
    }
    cout << "Min value: " << min << endl;
}

void A::display()
{
    cout << "ARRAY1 DISPLAY" << endl;

    for (int i = 0; i < this->size; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

void B::display()
{
    cout << "ARRAY2 DISPLAY" << endl;

    for (int i = 0; i < this->size; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    A a1;
    B b1;

    a1.display();
    b1.display();

    findMin(a1, b1);
}
