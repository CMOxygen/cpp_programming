#include <iostream>

/*
Написать программу, которая запрашивает с клавиатуры массив целых чисел и его размер,
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
using namespace std;

class Separator
{
private:
    int *arrayToSeparate = nullptr;
    int **results = nullptr;
    int arraySize = 0;
    int arraysCount = 3;

public:
    Separator();
    ~Separator();

    void userInput();
    void separate();

    int arrSum(int *arr);

    int maxValue(int *arr);
    int minValue(int *arr);

    int *nullify(int *arr);

    int **copyArray(int **arr);
};

Separator::Separator()
{
    arrayToSeparate = nullptr;
    results = nullptr;
    arraySize = 0;
    arraysCount = 3;
}

Separator::~Separator()
{
    delete[] arrayToSeparate;

    for (int i = 0; i < this->arraysCount; i++)
        delete[] results[i];

    delete[] results;
}

int Separator::maxValue(int *arr)
{
    int max = -10001010;

    for (int i = 0; i < arraySize; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int Separator::minValue(int *arr)
{
    int min = 100000;

    for (int i = 0; i < arraySize; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void Separator::separate()
{
    results = new int *[arraysCount];

    int *sums = new int[arraysCount];
    sums = nullify(sums);

    int **resultBuffer = results;
    int minDiff = 100000;

    for (int i = 0; i < arraysCount; i++)
    {
        results[i] = new int[arraySize];
        results[i] = nullify(results[i]);
    }

    for (int i = 0; i < arraySize; i++)
        cout << "[" << i << "] = " << arrayToSeparate[i] << "     ";

    cout << endl;

    int counter = 0;
    int firstSize = 1;
    int secondSize = arraySize - 2;
    int thirdSize = 1;
    bool status = true;

    while (false)
    {
        for (int i = 0; i < arraySize; i++)
            results[i] = nullify(results[i]);

        for (int i = 0; i < arraySize; i++)
        {
            if (i < firstSize)
            {
                results[0][i] = arrayToSeparate[i];
            }
            if (i >= firstSize && i <= arraySize - thirdSize)
            {
                results[1][i] = arrayToSeparate[i];
            }
            if (i > arraySize - thirdSize)
            {
                results[2][i] = arrayToSeparate[i];
            }
        }

        for (int i = 0; i < arraysCount; i++)
        {
            sums[i] = arrSum(results[i]);
            cout << "sum " << i << " = " << sums[i] << endl;
        }

        cout << "max    " << maxValue(sums) << endl;
        cout << "min " << minValue(sums) << endl;
        cout << "diff " << maxValue(sums) - minValue(sums) << endl;

        if (maxValue(sums) - minValue(sums) < minDiff)
        {
            minDiff = maxValue(sums) - minValue(sums);
            resultBuffer = copyArray(results);
            cout << "MINDIFF CHANGED" << endl;
        }

        status ? firstSize++ : thirdSize++;
        status = !status;
        counter++;
    }
    cout << "resultDiff " << minDiff << endl;

    for (int i = 0; i < arraysCount; i++)
    {
        cout << i << ":" << endl;

        for (int j = 0; j < arraySize; j++)
        {
            cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "    ";
        }
        cout << endl;
    }
}

int **Separator::copyArray(int **arr)
{
    int **newArray = new int *[arraysCount];

    for (int i = 0; i < arraysCount; i++)
    {
        newArray[i] = new int[arraySize];

        for (int j = 0; j < arraySize; j++)
            newArray[i][j] = arr[i][j];
    }
    return newArray;
}

void Separator::userInput()
{
    int size = 3;

    do
    {
        cout << "Enter size > 2" << endl;
        cin >> size;

    } while (size < 2);

    this->arraySize = size;

    this->arrayToSeparate = new int[this->arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        cout << "Enter element " << i << endl;
        cin >> arrayToSeparate[i];
    }
    separate();
}

int *Separator::nullify(int *arr)
{
    for (int i = 0; i < arraySize; i++)
        arr[i] = 0;

    return arr;
}

int Separator::arrSum(int *arr)
{
    int sum = 0;

    for (int i = 0; i < arraySize; i++)
        sum += arr[i];

    return sum;
}

// int arrSum(int *arr, int size);

// int maxValue(int *arr, const int size);
// int minValue(int *arr, const int size);

// int *nullify(int *arr, int size);

// int **copyArray(int **arr, int size, int arrCount);

int main(int argc, char **argv)
{
    Separator separator;
    separator.userInput();
    // separator.separate();
    // int size = 3;

    // do
    // {
    //     cout << "Enter size > 2" << endl;
    //     cin >> size;

    // } while (size < 2);

    // int *arr = new int[size];

    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter element " << i << endl;
    //     cin >> arr[i];
    // }

    // const int arrCount = 3;
    // int **result = new int *[arrCount];

    // int *sums = new int[arrCount];
    // sums = nullify(sums, arrCount);

    // int **resultBuffer = result;
    // int minDiff = 100000;

    // for (int i = 0; i < arrCount; i++)
    // {
    //     result[i] = new int[size];
    //     result[i] = nullify(result[i], size);
    // }

    // int counter = 0;
    // int firstSize = 1;
    // int secondSize = size - 2;
    // int thirdSize = 1;
    // bool status = true;

    // while (counter < size)
    // {
    //     for (int i = 0; i < arrCount; i++)
    //         result[i] = nullify(result[i], size);

    //     for (int i = 0; i < size; i++)
    //     {
    //         if (i < firstSize)
    //         {
    //             result[0][i] = arr[i];
    //         }
    //         if (i >= firstSize && i <= size - thirdSize)
    //         {
    //             result[1][i] = arr[i];
    //         }
    //         if (i > size - thirdSize)
    //         {
    //             result[2][i] = arr[i];
    //         }
    //     }

    //     for (int i = 0; i < arrCount; i++)
    //     {
    //         sums[i] = arrSum(result[i], size);
    //         cout << "sum " << i << " = " << sums[i] << endl;
    //     }

    //     cout << "max    " << maxValue(sums, arrCount) << endl;
    //     cout << "min " << minValue(sums, arrCount) << endl;
    //     cout << "diff " << maxValue(sums, arrCount) - minValue(sums, arrCount) << endl;

    //     if (maxValue(sums, arrCount) - minValue(sums, arrCount) < minDiff)
    //     {
    //         minDiff = maxValue(sums, arrCount) - minValue(sums, arrCount);
    //         resultBuffer = copyArray(result, size, arrCount);
    //         cout << "MINDIFF CHANGED" << endl;
    //     }

    //     status ? firstSize++ : thirdSize++;
    //     status = !status;
    //     counter++;
    // }
    // cout << "resultDiff " << minDiff << endl;

    // for (int i = 0; i < arrCount; i++)
    // {
    //     cout << i << ":" << endl;

    //     for (int j = 0; j < size; j++)
    //     {
    //         cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "    ";
    //     }
    //     cout << endl;
    // }
}

int **copyArray(int **arr, int size, int arrCount)
{
    int **newArray = new int *[arrCount];

    for (int i = 0; i < arrCount; i++)
    {
        newArray[i] = new int[size];

        for (int j = 0; j < size; j++)
            newArray[i][j] = arr[i][j];
    }
    return newArray;
}

int arrSum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

int *nullify(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 0;

    return arr;
}

int maxValue(int *arr, const int size)
{
    int max = -10001010;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int minValue(int *arr, const int size)
{
    int min = 100000;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}