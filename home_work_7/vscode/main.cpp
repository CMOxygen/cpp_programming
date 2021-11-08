#include <iostream>

using namespace std;

/* Написать программу, которая запрашивает 36 чисел целых, и формирует из них двумерный массив 6х6,
 * таким образом, чтобы сумма внутреннего, среднего и наружного контуров отличались межд собой минимально. 
 */

class Sorter
{
private:
    int **matrix;
    int **resultBuffer;

    const int resultSize = 6;

    int *inputArray;
    const int inputSize = 36;

    int *sumsArray;

    int minDiff;

public:
    Sorter();
    ~Sorter();

    void userInput();
    void displayResults();
    void sortArray();

    void debugInput();

    int arraySum(int *arr);
    int arraySum(int *arr, int size);

    int getIndexOf(int *arr, int value);
    int getAbsolute(int value);

    int minValue(int *arr);

    int maxValue(int *arr);
    int maxValue(int *arr, int size);

    int maxElement(int *arr);
    int minElement(int *arr);

    int *nullify(int *arr);

    int *removeItem(int *arr, int value);
    int *removeElement(int *arr, int index);

    int *insertItem(int *arr, int value);
    int *insertItem(int *arr, int value, int index);

    int **copyArray(int **arr);
};

Sorter::Sorter()
{
    matrix = nullptr;
    inputArray = nullptr;
    sumsArray = nullptr;

    minDiff = 0;
}

Sorter::~Sorter()
{
    for (int i = 0; i < resultSize; i++)
    {
        delete[] matrix[i];
        delete[] resultBuffer[i];

        matrix[i] = nullptr;
        resultBuffer[i] = nullptr;
    }

    delete[] matrix;
    delete[] resultBuffer;
    delete[] inputArray;
    delete[] sumsArray;

    matrix = nullptr;
    resultBuffer = nullptr;
    inputArray = nullptr;
    sumsArray = nullptr;
}

int Sorter::getAbsolute(int value)
{
    if (value > 0)
    {
        return value;
    }
    else
    {
        return value * (-1);
    }
}

int Sorter::minValue(int *arr)
{
    int min = arr[0];

    for (int i = 1; i < resultSize; i++)
    {
        if (arr[i] < min && arr[i] != 0)
        {
            min = arr[i];
        }
    }
    return min;
}

int Sorter::maxValue(int *arr)
{
    int max = arr[0];

    for (int i = 1; i < resultSize; i++)
    {
        if (arr[i] > max && arr[i] != 0)
        {
            max = arr[i];
        }
    }
    return max;
}

int Sorter::maxValue(int *arr, int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max && arr[i] != 0)
        {
            max = arr[i];
        }
    }
    return max;
}

int Sorter::maxElement(int *arr)
{
    int max = arr[0];
    int index = 0;

    for (int i = 1; i < resultSize; i++)
    {
        if (arr[i] > max && arr[i] != 0)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

int Sorter::minElement(int *arr)
{
    int min = arr[0];
    int index = 0;

    for (int i = 1; i < resultSize; i++)
    {
        if (arr[i] < min && arr[i] != 0)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

int Sorter::getIndexOf(int *arr, int value)
{
    for (int i = 0; i < resultSize; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int Sorter::arraySum(int *arr)
{
    int sum = 0;

    for (int i = 0; i < resultSize; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int Sorter::arraySum(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int *Sorter::removeElement(int *arr, int index)
{
    arr[index] = 0;

    return arr;
}

int *Sorter::removeItem(int *arr, int value)
{
    for (int i = 0; i < resultSize; i++)
    {
        if (arr[i] == value)
        {
            arr[i] = 0;
        }
    }
    return arr;
}

int *Sorter::insertItem(int *arr, int value)
{
    for (int i = 0; i < resultSize; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = value;
            return arr;
        }
    }
    return arr;
}

int *Sorter::insertItem(int *arr, int value, int index)
{
    if (index < resultSize)
    {
        arr[index] = value;
    }
    return arr;
}

int *Sorter::nullify(int *arr)
{
    arr = new int[resultSize];

    for (int i = 0; i < resultSize; i++)
    {
        arr[i] = 0;
    }
    return arr;
}

void Sorter::debugInput()
{
    inputArray = new int[inputSize];

    for (int i = 0; i < inputSize; i++)
    {
        inputArray[i] = i + 1;
    }
}

void Sorter::sortArray()
{
    int counter = 0;
    int inputArrayIndex = 0;

    int *minArray;
    int *maxArray;

    minDiff = arraySum(inputArray, inputSize);
    cout << "FIRST MAX = " << minDiff << endl;

    matrix = new int *[resultSize];
    resultBuffer = new int *[resultSize];

    sumsArray = new int[resultSize];

    for (int i = 0; i < resultSize; i++)
    {
        matrix[i] = new int[resultSize];
        matrix[i] = nullify(matrix[i]);

        resultBuffer[i] = new int[resultSize];
        resultBuffer[i] = nullify(resultBuffer[i]);
    }

    sumsArray = nullify(sumsArray);

    for (int i = 0; i < resultSize; i++)
    {
        for (int j = 0; j < resultSize; j++)
        {
            matrix[i][j] = inputArray[inputArrayIndex];
            inputArrayIndex++;
        }
    }

    while (counter < 10)
    {
        cout << "COUNTER = " << counter << endl;

        sumsArray = nullify(sumsArray);

        for (int i = 0; i < resultSize; i++)
        {
            sumsArray[i] = arraySum(matrix[i]);
            cout << "SUMS ARRAY [" << i << "] = " << sumsArray[i] << endl;
        }

        for (int i = 0; i < resultSize; i++)
        {
            cout << "MIN " << i << " = " << minValue(matrix[i]) << endl;
            cout << "MAX " << i << " = " << maxValue(matrix[i]) << endl;
        }

        cout << "MIN INDEX: " << getIndexOf(sumsArray, minValue(sumsArray)) << endl;
        cout << "MAX INDEX: " << getIndexOf(sumsArray, maxValue(sumsArray)) << endl;
        cout << "ANOTHER MAX INDEX: " << maxElement(sumsArray) << endl;
        cout << "ANOTHER MIN INDEX: " << minElement(sumsArray) << endl;
        cout << "DIFF: " << getAbsolute(maxValue(sumsArray) - minValue(sumsArray)) << endl;

        if (getAbsolute(maxValue(sumsArray) - minValue(sumsArray)) < minDiff)
        {
            resultBuffer = copyArray(matrix);
            minDiff = getAbsolute(maxValue(sumsArray) - minValue(sumsArray));
        }

        cout << "sort array: " << endl;
        displayResults();

        minArray = matrix[minElement(sumsArray)];
        maxArray = matrix[maxElement(sumsArray)];

        cout << "MIN ARRAY" << endl;
        for (int i = 0; i < resultSize; i++)
            cout << "[" << i << "] = " << minArray[i] << "  ";
        cout << endl;

        cout << "MAX ARRAY" << endl;
        for (int i = 0; i < resultSize; i++)
            cout << "[" << i << "] = " << maxArray[i] << "  ";
        cout << endl;

        // int temp = minValue(minArray);
        int temp = maxValue(minArray);
        minArray = insertItem(minArray, minValue(maxArray), maxElement(minArray));
        maxArray = insertItem(maxArray, temp, minElement(maxArray));

        counter++;
    }
}

void Sorter::displayResults()
{
    cout << "INPUT ARRAY: " << endl;

    for (int i = 0; i < inputSize; i++)
    {
        cout << "[" << i << "] = " << inputArray[i] << "   ";
    }
    cout << endl;

    cout << "MATRIX ARRAY: " << endl;

    for (int i = 0; i < resultSize; i++)
    {
        for (int j = 0; j < resultSize; j++)
        {
            cout << "[" << i << "][" << j << "] = " << matrix[i][j] << "    ";
        }
        cout << endl;
    }

    cout << "RESULT ARRAY: " << endl;

    for (int i = 0; i < resultSize; i++)
    {
        for (int j = 0; j < resultSize; j++)
        {
            cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "      ";
        }
        cout << endl;
    }
    cout << "minDiff: " << minDiff << endl;
}

void Sorter::userInput()
{
    inputArray = new int[inputSize];

    for (int i = 0; i < inputSize; i++)
    {
        cout << "Enter element " << i << endl;
        cin >> inputArray[i];
    }
}

int **Sorter::copyArray(int **arr)
{
    int **newArr = new int *[resultSize];

    for (int i = 0; i < resultSize; i++)
    {
        newArr[i] = new int[resultSize];
        newArr[i] = nullify(newArr[i]);

        for (int j = 0; j < resultSize; j++)
        {
            newArr[i][j] = arr[i][j];
        }
    }
    return newArr;
}

int main(int argc, char **argv)
{
    Sorter *sorter = new Sorter();
    // sorter->userInput();
    sorter->debugInput();
    sorter->sortArray();
    sorter->displayResults();

    system("PAUSE");
}
