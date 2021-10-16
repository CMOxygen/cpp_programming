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

class ArraySorter
{
private:
    int *userInputArray = nullptr;
    int inputArraySize = 0;

    int **arr = nullptr;
    int height = 0;
    int width = 0;

    int **resultBuffer = nullptr;
    int resultHeight = 0;
    int resultWidth = 0;

public:
    ArraySorter();
    ~ArraySorter();

    void userInput();
    void sortArray();
    void displayResults();

    int **copyArray(int **arr);
    int **newArray();

    int *appendArray(int *arr, int value);
    int *nullify(int *arr, int size);

    int sumV(int **arr);
    int sumV(int **arr, int size);
    int sumH(int **arr);
    int sumH(int **arr, int size);
    int getAbs(int value);
};

ArraySorter::ArraySorter()
{
    arr = nullptr;
    height = 0;
    width = 0;

    resultBuffer = nullptr;
    resultHeight = 0;
    resultWidth = 0;

    userInputArray = nullptr;
    inputArraySize = 0;
}

ArraySorter::~ArraySorter()
{
    for (int i = 0; i < height; i++)
    {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    for (int i = 0; i < resultHeight; i++)
    {
        delete[] resultBuffer[i];
        resultBuffer[i] = nullptr;
    }

    delete[] arr;
    delete[] resultBuffer;
    delete[] userInputArray;

    arr = nullptr;
    userInputArray = nullptr;
    resultBuffer = nullptr;
}

int **ArraySorter::copyArray(int **arr)
{
    int **newArray = new int *[height];

    for (int i = 0; i < height; i++)
    {
        newArray[i] = new int[width];
        newArray[i] = nullify(newArray[i], width);

        for (int j = 0; j < width; j++)
            newArray[i][j] = arr[i][j];
    }
    return newArray;
}

int **ArraySorter::newArray()
{
    int **newArray = new int *[height];

    for (int i = 0; i < height; i++)
    {
        newArray[i] = new int[width];
        newArray[i] = nullify(newArray[i], width);
    }
    return newArray;
}

int ArraySorter::getAbs(int value)
{
    if (value < 0)
        return value * -1;
    else
        return value;
}

int ArraySorter::sumH(int **arr)
{
    int sum = 0;

    for (int i = 0; i < width; i++)
        sum += arr[0][i];
    return sum;
}

int ArraySorter::sumH(int **arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[0][i];
    return sum;
}

int ArraySorter::sumV(int **arr)
{
    int sum = 0;

    for (int i = 0; i < height; i++)
        sum += arr[i][0];
    return sum;
}

int ArraySorter::sumV(int **arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i][0];
    return sum;
}

void ArraySorter::displayResults()
{
    cout << "RESULT BUFFER: " << endl;

    for (int i = 0; i < resultHeight; i++)
    {
        for (int j = 0; j < resultWidth; j++)
            cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "    ";
        cout << endl;
    }
    cout << "sumV = " << sumV(resultBuffer, resultHeight) << endl;
    cout << "sumH = " << sumH(resultBuffer, resultWidth) << endl;
    cout << "sumV - sumH = " << getAbs(sumV(resultBuffer, resultHeight) - sumH(resultBuffer, resultWidth)) << endl;
}

void ArraySorter::sortArray()
{
    int counter = 0;
    int inputArrayIndex = 0;
    int diff = 1000000;

    height = 1;

    while (height < inputArraySize)
    {
        for (int i = 0; i < height - 1; i++)
        {
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;

        inputArrayIndex = 0;

        if (inputArraySize % height == 0)
        {
            width = inputArraySize / height;
        }
        else
        {
            width = inputArraySize / height + 1;
        }

        arr = new int *[height];

        for (int i = 0; i < height; i++)
        {
            arr[i] = new int[width];
            arr[i] = nullify(arr[i], width);

            for (int j = 0; j < width; j++)
            {
                if (inputArrayIndex >= inputArraySize)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = userInputArray[inputArrayIndex];
                }
                cout << "[" << i << "][" << j << "] = " << arr[i][j] << "   ";

                inputArrayIndex++;
            }
            cout << endl;
        }
        cout << endl;
        if (getAbs(sumV(arr) - sumH(arr)) < diff)
        {
            diff = getAbs(sumV(arr) - sumH(arr));
            resultBuffer = copyArray(arr);
            resultHeight = height;
            resultWidth = width;
        }
        cout << "sumV = " << sumV(arr) << endl;
        cout << "sumH = " << sumH(arr) << endl;
        cout << "sumV - sumH = " << getAbs(sumV(arr) - sumH(arr)) << endl;
        cout << "diff = " << diff << endl;

        height++;
    }
}

int *ArraySorter::nullify(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 0;

    return arr;
}

void ArraySorter::userInput()
{
    int value = 1;

    inputArraySize = 0;

    while (value != 0 || inputArraySize <= 0)
    {
        cout << "Enter new value:" << endl;
        cin >> value;

        if (value == 0)
            break;

        userInputArray = appendArray(userInputArray, value);
    }

    for (int i = 0; i < inputArraySize; i++)
        cout << "[" << i << "] = " << userInputArray[i] << "   ";

    cout << endl;
}

int *ArraySorter::appendArray(int *arr, int value)
{
    int *newArray = new int[inputArraySize + 1];
    newArray = nullify(newArray, inputArraySize + 1);

    for (int i = 0; i < inputArraySize; i++)
        newArray[i] = arr[i];

    newArray[inputArraySize] = value;
    inputArraySize++;

    return newArray;
}

int main(int argc, char **argv)
{
    ArraySorter sorter;
    sorter.userInput();
    sorter.sortArray();
    sorter.displayResults();
}