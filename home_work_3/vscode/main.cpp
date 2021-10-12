#include <iostream>

using namespace std;

/* 
 *  Написать программу, которая запрашивает с клавиатуры массив целых чисел и его размер,
    после чего, делит его на 3 части(создает 3 новых массива).
    поделить необходимо так, чтобы суммы элементов получившихся частей различались минимально.
    Реализовать в объектно-ориентированном стиле, для этого, написать класс.
    В качестве данных указатели, размеры массива и др. необ. параметры и данные.
    В качестве методов:
        Конструктор инициализирующий указатели и размеры массивов нулями,
        Деструктор, освобождающий память(как шаблон см. практ4_3).

    Методы:
        метод для создания массива(пользовательский ввод). (*обесп. возможность перезаписи).
        метод оптималально делящий основой массив на 3 части, он же создает 3 производных массива,
            заполнив их элементами.
        метод для вывода результатов на экран.(1 массива, 3 получившихся и макс. разность)

    Доп. условие:
        Обеспечить корректность работы, в случае, если методы будут вызываться не по порядку.
            (просто не должны работать).

    Дружественный интерфейс.
    Дополнительным библиотеками пользоваться нельзя. 
 */

class Separator
{
private:
    int arraySize = 3;
    int length = arraySize;

    int *arrayToSeparate;

    int *resultArray1;
    int *resultArray2;
    int *resultArray3;

public:
    Separator();
    ~Separator();

    void userInput();
    void displayResults();
    void separate();

    int *nullify(int *arr);
    int *removeElement(int *arr, const int index);
    // int *append(int arr*,int size, int value);

    int maxValue(int *arr);
    int maxIndex(int *arr);
    int minValue(int *arr);
    int minIndex(int *arr);
    int sum(int *array);
    int maxValueLessThan(int *arr, int number);
    int minValueGreaterThan(int *arr, int number);

    bool isEven(int number);
    bool contains(int *arr, int number);
};

int Separator::sum(int *array)
{
    int sum = 0;

    for (int i = 0; i < length; i++)
        sum += array[i];

    return sum;
}

Separator::Separator()
{
    arraySize = 3;
    arrayToSeparate = nullptr;
    resultArray2 = nullptr;
    resultArray3 = nullptr;
    resultArray1 = nullptr;
}

Separator::~Separator()
{
    delete[] arrayToSeparate;
    delete[] resultArray1;
    delete[] resultArray3;
    delete[] resultArray2;
}

bool Separator::isEven(int number)
{
    return number % 2 == 0;
}

bool Separator::contains(int *arr, int number)
{
    for (int i = 0; i < number; i++)
        if (arr[i] == number)
            return true;

    return false;
}

int Separator::maxValue(int *arr)
{
    int max = arr[0];

    for (int i = 0; i < arraySize; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int Separator::maxIndex(int *arr)
{
    int max = 0;
    int index = 0;

    for (int i = 0; i < arraySize; i++)
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }

    return index;
}

int Separator::minValue(int *arr)
{
    int min = arr[0];

    for (int i = 0; i < arraySize; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

int Separator::minIndex(int *arr)
{
    int min = 100000;
    int index = 0;

    for (int i = 0; i < arraySize; i++)
        if (arr[i] > min)
        {
            min = arr[i];
            index = i;
        }

    return index;
}

int Separator::maxValueLessThan(int *arr, int number)
{
    int max = 0;

    for (int i = 0; i < arraySize; i++)
        if (arr[i] > max && arr[i] < number)
            max = arr[i];

    return max;
}
int Separator::minValueGreaterThan(int *arr, int number)
{
    int min = 100000;

    for (int i = 0; i < arraySize; i++)
        if (arr[i] < min && arr[i] > number)
            min = arr[i];

    return min;
}

void Separator::userInput()
{
    int size = 3;

    do
    {
        cout << "Enter size of array > 2" << endl;
        cin >> size;

    } while (size < 3);

    int *arr = nullptr;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << " of array" << endl;
        cin >> arr[i];
    }
    arraySize = size;
    arrayToSeparate = arr;

    resultArray1 = new int[arraySize];
    resultArray2 = new int[arraySize];
    resultArray3 = new int[arraySize];

    resultArray1 = nullify(resultArray1);
    resultArray2 = nullify(resultArray2);
    resultArray3 = nullify(resultArray3);

    arr = nullptr;
}

void Separator::displayResults()
{
    cout << maxValue(arrayToSeparate) << "      " << minValue(arrayToSeparate) << endl;
    cout << "Array to separate:" << endl;
    for (int i = 0; i < length; i++)
        cout << arrayToSeparate[i] << "     ";

    cout << endl;
    cout << "sum = " << sum(arrayToSeparate) << endl;

    cout << "Result Array 1" << endl;
    for (int i = 0; i < length; i++)
        cout << resultArray1[i] << "     ";

    cout << endl;
    cout << "sum = " << sum(resultArray1) << endl;

    cout << "Result Array 2" << endl;
    for (int i = 0; i < length; i++)
        cout << resultArray2[i] << "    ";

    cout << endl;
    cout << "sum = " << sum(resultArray2) << endl;

    cout << "Result Array 3" << endl;
    for (int i = 0; i < length; i++)
        cout << resultArray3[i] << "    ";

    cout << endl;
    cout << "sum = " << sum(resultArray3) << endl;
}

int *Separator::removeElement(int *arr, const int index)
{
    int *newArray = nullptr;
    newArray = new int[arraySize - 1];

    for (int i = 0; i < arraySize; i++)
    {
        if (i > index)
        {
            newArray[i - 1] = arr[i];
        }
        else
        {
            if (i != index)
                newArray[i] = arr[i];
        }
    }
    arraySize--;
    return newArray;
}

void Separator::separate()
{
    length = arraySize;
    int max = maxValue(arrayToSeparate);
    int min = minValue(arrayToSeparate);

    int size = arraySize / 3;

    int arraysCount = 3;
    int **resultArrays = nullptr;
    resultArrays = new int *[arraysCount];

    resultArrays[0] = resultArray1;
    resultArrays[1] = resultArray2;
    resultArrays[2] = resultArray3;

    if (arraySize % 3 != 0)
        size++;

    cout << "size:  " << size << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < arraysCount; j++)
        {
            if (isEven(i))
            {
                max = maxValueLessThan(arrayToSeparate, max);
                resultArrays[j][i] = max;
            }
            else
            {
                min = minValueGreaterThan(arrayToSeparate, min);
                resultArrays[j][i] = min;
            }
        }
    }
    resultArray1 = resultArrays[0];
    resultArray2 = resultArrays[1];
    resultArray3 = resultArrays[2];
}

int *Separator::nullify(int *arr)
{
    for (int i = 0; i < arraySize; i++)
        arr[i] = 0;

    return arr;
}

int main(int argc, char **argv)
{
    // int *array = nullptr;
    // array = new int[6];

    // for (int i = 0; i < 6; i++)
    // {
    //     array[i] = i + 1;
    //     cout << array[i] << "   ";
    // }
    // cout << endl;

    Separator separator;
    separator.userInput();
    separator.separate();
    separator.displayResults();

    // cout << "MAX: " << separator.maxValueLessThan(array, 3) << endl;

    return 0;
}
