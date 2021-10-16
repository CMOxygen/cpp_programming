#include <iostream>

/*
1. Написать класс, который реализует динамический двумерный массив, в нем метод, который запрашивает с клавиатуры размеры 
массива, создает массив, потом просит запонить его с клавиатуры.
Другой метод выводит на экран этот массив. Конструктор и деструктор предусмотрите для безопасной работы с динамической памятью.

2.  Написать программу, которая запрашивает у пользовател последовательность натуральных чисел (размер не запрашивается). 
Пользователь вводит сколько хочет, когда надоест - введет "0". Далее, из этой последовательности формируется двумерный массив:
наиболее подходящего размера, элементы, на которые не хватило чисел, заполняются нулями. Сортируйте данные внутри 
двумерного массива так, чтобы суммы элементов первой строки, и сумма элементов первого столбца, были максимально близки по значению.
Реализовать в стиле ооп, дополнительных библиотек не подключать, предусмотреть дружественный интерфейс.
*/

using namespace std;

class TwoDimensionalArray
{
private:
    int **arr = nullptr;
    int width = 0;
    int height = 0;

public:
    TwoDimensionalArray();
    ~TwoDimensionalArray();

    void userInput();
    void displayArray();
};

TwoDimensionalArray::TwoDimensionalArray()
{
    arr = nullptr;
    width = 0;
    height = 0;
}

TwoDimensionalArray::~TwoDimensionalArray()
{
    for (int i = 0; i < height; i++)
        delete[] arr[i];

    delete[] arr;
    arr = nullptr;
}

void TwoDimensionalArray::userInput()
{
    int w = 2;
    int h = 2;

    do
    {
        cout << "Enter height > 1..." << endl;
        cin >> h;
    } while (h < 1);

    do
    {
        cout << "Enter width > 1..." << endl;
        cin >> w;
    } while (w < 1);

    this->height = h;
    this->width = w;

    arr = new int *[height];

    for (int i = 0; i < height; i++)
    {
        arr[i] = new int[width];

        for (int j = 0; j < width; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]:" << endl;
            cin >> arr[i][j];
        }
    }
}

void TwoDimensionalArray::displayArray()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[" << i << "][" << j << "] = " << arr[i][j] << "    ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    TwoDimensionalArray tda;
    tda.userInput();
    tda.displayArray();
}