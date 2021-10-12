#include <iostream>

using namespace std;

int *userInput(const int size);
void displayArray(int *array, int size);
void separate(int *arrayToSeparate, int size);

int maxValue(int *arr, int size);
int minValue(int *arr, int size);

int maxValueLessThan(int *arr, int value, int size);
int minValueGreaterThan(int *arr, int number, int size);

int *nullify(int *arr, int size);

int sum(int *arr, int size);

int *add(int *arr, int size, int value);
int *remove(int *arr, int size, int index);

bool contains(int *arr, int size, int value);

int main(int argc, char **argv)
{
    int size = 1;

    do
    {
        cout << "Enter size > 0" << endl;
        cin >> size;

    } while (size < 1);

    int *arr = userInput(size);
    displayArray(arr, size);
    separate(arr, size);

    return 0;
}

int *add(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = value;
            return arr;
        }
    }
    return arr;
}

int *remove(int *arr, int size, int index)
{
    arr[index] = 0;
    return arr;
    // int *result = arr;

    // for (int i = 0; i < size; i++)
    // {
    // if (i == index)
    //     continue;

    // if (i < index)
    // {
    //     result[i] = arr[i];
    // }
    // else
    // {
    //     result[i - 1] = arr[i];
    // }

    // }
    // result[size - 1] = 0;

    // return result;
}

bool contains(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return true;
    }
    return false;
}

int *nullify(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 0;

    return arr;
}

int sum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int *userInput(const int size)
{
    int *array = nullptr;
    array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << endl;
        cin >> array[i];
    }
    return array;
}

void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << "   ";
    cout << endl;
}

void separate(int *arr, int size)
{
    const int resultsNumber = 2;

    int max = maxValue(arr, size) + 1;
    int min = minValue(arr, size) - 1;

    cout << max << " " << min << endl;
    cout << "Sum " << sum(arr, size) << endl;

    int *result1 = new int[size];
    int *result2 = new int[size];

    int **results = new int *[resultsNumber];
    results[0] = nullify(result1, size);
    results[1] = nullify(result2, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < resultsNumber; j++)
        {
            if (maxValueLessThan(arr, max, size) == max)
                break;

            max = maxValueLessThan(arr, max, size);
            results[j][i] = max;
            cout << "max " << max << endl;
        }
    }

    int maxSum = 0;
    int maxSumArray = 0;
    int sumDiff = 0;
    int anotherArray = 0;

    if (sum(results[0], size) > sum(results[1], size))
    {
        maxSum = sum(results[0], size);
        sumDiff = sum(results[0], size) - sum(results[1], size);
        maxSumArray = 0;
        anotherArray = 1;
    }
    else
    {
        maxSum = sum(results[1], size);
        sumDiff = sum(results[1], size) - sum(results[0], size);
        maxSumArray = 1;
        anotherArray = 0;
    }

    for (int i = 0; i < resultsNumber; i++)
    {
        cout << i << ", sum = " << sum(results[i], size) << ":" << endl;

        for (int j = 0; j < size; j++)
        {
            cout << i << ";" << j << "=" << results[i][j] << "     ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++)
    {
        if (results[maxSumArray][i] <= sumDiff && results[maxSumArray][i] != 0)
        {
            results[maxSumArray] = remove(results[maxSumArray], size, i);
            results[anotherArray] = add(results[anotherArray], size, results[maxSumArray][i]);
            break;
        }
    }

    for (int i = 0; i < resultsNumber; i++)
    {
        cout << i << ", sum = " << sum(results[i], size) << ":" << endl;

        for (int j = 0; j < size; j++)
        {
            cout << i << ";" << j << "=" << results[i][j] << "     ";
        }
        cout << endl;
    }
}

int maxValue(int *arr, int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int minValue(int *arr, int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int maxValueLessThan(int *arr, int value, int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] > max && arr[i] < value)
            max = arr[i];
    return max;
}

int minValueGreaterThan(int *arr, int value, int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
        if (arr[i] < min && arr[i] > value)
            min = arr[i];
    return min;
}