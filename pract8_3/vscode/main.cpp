#include <iostream>

/*
    Дружественные функции позволяют использовать одну функцию 
    двумя разными классами.
*/

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
    static const unsigned int size{10};
    int arr[size];

public:
    A() : arr{1, 2, 3, 4, 5, 6, 7, 8, 9} {}
    friend void friendDisplay(const A &ob1, const B &ob2);
};

class B
{
private:
    static const unsigned int size{6};
    int arr[size];

public:
    B() : arr{2, 4, 6, 8, 10, 12} {}
    friend void friendDisplay(const A &ob1, const B &ob2);
};

void friendDisplay(const A &ob1, const B &ob2)
{
    const unsigned int theSize = ob1.size + ob2.size;

    int arrayToDisplay[theSize];
    int buff;

    unsigned int j = 0;

    for (unsigned int i = 0; i < ob1.size; i++)
    {
        arrayToDisplay[j++] = ob1.arr[i];
    }
    for (unsigned int i = 0; i < ob2.size; i++)
    {
        arrayToDisplay[j++] = ob2.arr[i];
    }
    for (unsigned int i = 0; i < theSize - 1; i++)
    {
        for (unsigned int j = 0; j < theSize - 1 - i; j++)
        {
            buff = arrayToDisplay[j];
            arrayToDisplay[j] = arrayToDisplay[j + 1];
            arrayToDisplay[j + 1] = buff;
        }
    }

    cout << " Result of combination sort: " << endl;

    for (unsigned int i = 0; i < theSize; i++)
    {
        cout << arrayToDisplay[i] << "   ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    A a1;
    B b1;

    friendDisplay(a1, b1);
}
