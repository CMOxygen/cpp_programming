#include <iostream>

using namespace std;

int *userInput(const int size);
int *nullify(int *arr, int size);
int *removeElement(int *arr, int size, int index);
int *addElement(int *arr, int size, int value);
int **sortDescending(int **arr, int size, int arrCount);

int userSize();
int sum(int *arr, int size);
int absolute(int value);
int indexOf(int *arr, int size, int value);

double absDouble(double value);

int maxValue(int *arr, const int size);
int maxValue(int *arr, const int size, const int value);
int maxElement(int *arr, const int size);
int maxElement(int *arr, const int size, const int value);

int minValue(int *arr, const int size);

int maxValue2(int *arr, const int size, const int value);

void separate(int *arr, const int size);

int main(int argc, char **argv)
{
    const int size = userSize();
    int *arrayToSeparate = userInput(size);

    separate(arrayToSeparate, size);
}

double absDouble(double value)
{
    if (value < 0)
    {
        return value * -1;
    }
    else
    {
        return value;
    }
}

int minValue(int *arr, const int size)
{
    int min = 100000;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min && arr[i] != 0)
            min = arr[i];
    }
    return min;
}

int indexOf(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i;
}

int maxValue2(int *arr, const int size, const int value)
{
    int max = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] > max && arr[i] <= value)
            max = arr[i];

    return max;
}

int maxElement(int *arr, const int size, const int value)
{
    int max = arr[0];
    int element = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max && arr[i] < value)
        {
            max = arr[i];
            element = i;
        }
    }
    return element;
}

int maxElement(int *arr, const int size)
{
    int max = arr[0];
    int element = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            element = i;
        }
    }
    return element;
}

int **sortDescending(int **arr, int size, int arrCount)
{
    int *sums = new int[arrCount];
    sums = nullify(sums, arrCount);

    int *sumsSorted = new int[arrCount];
    sumsSorted = nullify(sumsSorted, arrCount);

    int **sortedArray = new int *[arrCount];

    int max = 0;
    int prevMax = 0;
    int value = 100000;
    int counter = 0;
    int temp = 0;

    for (int i = 0; i < arrCount; i++)
    {
        sums[i] = sum(arr[i], size);
    }
    for (int i = 0; i < arrCount; i++)
    {
        if (sums[i] == temp)
            counter++;

        temp = sums[i];
    }
    if (counter == arrCount - 1)
        return arr;

    for (int i = 0; i < arrCount; i++)
    {
        for (int j = 0; j < arrCount; j++)
        {
            if (sums[j] > max && sums[j] < value)
                max = sums[j];
        }
        sumsSorted[i] = max;
        value = max;

        if (max == 0)
        {
            sumsSorted[i] = prevMax;
            value = prevMax;
        }

        prevMax = max;

        cout << "max value " << i << " = " << max << endl;
        cout << "sumsSorted" << i << " = " << sumsSorted[i] << endl;

        max = 0;
    }

    for (int i = 0; i < arrCount; i++)
    {
        cout << "sum " << i << " = " << sums[i] << endl;
        // cout << "sumSorted " << i << " = " << sumsSorted[i] << endl;
    }

    for (int i = 0; i < arrCount; i++)
    {
        for (int j = 0; j < arrCount; j++)
        {
            if (sum(arr[i], size) == sumsSorted[j])
            {
                sortedArray[j] = arr[i];
            }
        }
    }

    return sortedArray;
}

int *removeElement(int *arr, const int size, int index)
{
    arr[index] = 0;
    return arr;
}

int *addElement(int *arr, const int size, int value)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == 0)
        {
            arr[i] = value;
            break;
        }
    return arr;
}

int absolute(int value)
{
    if (value < 0)
        value *= -1;

    return value;
}

int sum(int *arr, const int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

int maxValue(int *arr, const int size)
{
    int max = arr[0];

    for (int i = 0; i < size; i++)
        if (max < arr[i])
            max = arr[i];

    return max;
}

int maxValue(int *arr, const int size, const int value)
{
    int max = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] > max && arr[i] < value)
            max = arr[i];

    return max;
}

int *userInput(const int size)
{
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << endl;
        cin >> arr[i];
    }
    return arr;
}

int *nullify(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    return arr;
}

void separate(int *arr, const int size)
{
    const int arraysCount = 3;

    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] = " << arr[i] << "   ";
    }
    cout << endl;

    int max = maxValue(arr, size) + 1;

    int arrSum = sum(arr, size);
    double meanValue = (double)arrSum / (double)arraysCount;

    int **results = new int *[arraysCount];

    for (int i = 0; i < arraysCount; i++)
    {
        results[i] = new int[size];
        results[i] = nullify(results[i], size);
    }

    for (int i = 0; i < arraysCount; i++)
    {
        for (int j = 0; j < arraysCount; j++)
        {
            if (maxValue(arr, size, max) != max)
            {
                max = maxValue(arr, size, max);
                results[j][i] = max;
            }
        }
    }

    for (int i = 0; i < arraysCount; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "," << j << "] = " << results[i][j] << "   ";
        }
        cout << endl;
    }
    int deltaResults = 0;
    int element = 0;
    int counter = 0;
    bool run = true;

    while (run)
    {
        element = indexOf(results[0], size, minValue(results[0], size));

        for (int i = 0; i < size; i++)
            if (results[2][i] == 0)
            {
                results[2][i] = minValue(results[0], size);
                break;
            }
        results[0][element] = 0;

        results = sortDescending(results, size, arraysCount);

        cout << "COUNTER = " << counter << endl;

        for (int i = 0; i < arraysCount; i++)
        {
            cout << i << ", sum = " << sum(results[i], size) << ":" << endl;

            for (int j = 0; j < size; j++)
            {
                cout << "[" << i << "," << j << "] = " << results[i][j] << "   ";
            }
            cout << endl;
        }
        counter++;

        if (size % 3 == 0)
        {
            run = absDouble((double)sum(results[0], size) - meanValue) > 0 || absDouble((double)sum(results[1], size) - meanValue) > 0 || absDouble((double)sum(results[2], size) - meanValue) > 0;
        }
        else
        {
            run = absDouble((double)sum(results[0], size) - meanValue) > 1 || absDouble((double)sum(results[1], size) - meanValue) > 1 || absDouble((double)sum(results[2], size) - meanValue) > 1;
        }
    }

    for (int i = 0; i < arraysCount; i++)
    {
        cout << i << ", sum = " << sum(results[i], size) << ":" << endl;

        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "," << j << "] = " << results[i][j] << "   ";
        }
        cout << endl;
    }
}

int userSize()
{
    int size = 3;

    do
    {
        cout << "Enter size > 2:" << endl;
        cin >> size;

    } while (size < 3);

    return size;
}