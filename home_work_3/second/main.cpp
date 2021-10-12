#include <iostream>

using namespace std;

int arrSum(int *arr, int size);

int maxValue(int *arr, const int size);
int minValue(int *arr, const int size);

int *nullify(int *arr, int size);

int main(int argc, char **argv)
{

    int size = 3;

    do
    {
        cout << "Enter size > 2" << endl;
        cin >> size;
    } while (size < 2);

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "] = " << arr[i] << "   ";
    }
    cout << endl;

    const int arrCount = 3;
    int **result = new int *[arrCount];

    int *sums = new int[arrCount];
    sums = nullify(sums, arrCount);

    int **resultBuffer = result;
    int minDiff = 100000;

    for (int i = 0; i < arrCount; i++)
    {
        result[i] = new int[size];
        result[i] = nullify(result[i], size);
    }

    int counter = 0;

    int firstSize = 1;
    int secondSize = size - 2;
    int thirdSize = 1;

    bool status = true;

    while (counter < 7)
    {

        for (int i = 0; i < arrCount; i++)
            result[i] = nullify(result[i], size);

        for (int i = 0; i < size; i++)
        {
            if (i < firstSize)
            {
                result[0][i] = arr[i];
            }
            if (i >= firstSize && i <= size - thirdSize)
            {
                result[1][i] = arr[i];
            }
            if (i > size - thirdSize)
            {
                result[2][i] = arr[i];
            }
        }

        for (int i = 0; i < arrCount; i++)
        {
            sums[i] = arrSum(result[i], size);
            cout << "sum " << i << " = " << sums[i] << endl;
        }

        cout << "max    " << maxValue(sums, arrCount) << endl;
        cout << "min " << minValue(sums, arrCount) << endl;
        cout << "diff " << maxValue(sums, arrCount) - minValue(sums, arrCount) << endl;

        if (maxValue(sums, arrCount) - minValue(sums, arrCount) == minDiff)
        {
            for (int i = 0; i < arrCount; i++)
            {
                cout << i << ":" << endl;

                for (int j = 0; j < size; j++)
                {
                    cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "    ";
                }
                cout << endl;
            }
            break;
        }

        if (maxValue(sums, arrCount) - minValue(sums, arrCount) < minDiff)
        {
            minDiff = maxValue(sums, arrCount) - minValue(sums, arrCount);
            resultBuffer = result;
        }

        status ? firstSize++ : thirdSize++;
        status = !status;

        // for (int i = 0; i < arrCount; i++)
        // {
        //     cout << i << ":" << endl;

        //     for (int j = 0; j < size; j++)
        //     {
        //         cout << "[" << i << "][" << j << "] = " << result[i][j] << "    ";
        //     }
        //     cout << endl;
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
        counter++;
    }
    cout << "resultDiff " << minDiff << endl;

    for (int i = 0; i < arrCount; i++)
    {
        cout << i << ":" << endl;

        for (int j = 0; j < size; j++)
        {
            cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "    ";
        }
        cout << endl;
    }
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