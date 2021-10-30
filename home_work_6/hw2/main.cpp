#include <iostream>

using namespace std;

/*  2. С клавиатуры вводится массив вещественных чисел, эти числа нужно поделить на две группы таким образом, 
 *  чтобы дробная часть суммы чисел и в первой и во второй группе была минимальна. Повторы запрещены.
 *  
 *  Массив из 4 чисел {5.5, 3.5, 1.7, 21.4} 
 *  1: 9.0
 *  2: 23.1
*/

class DoubleSeparator
{
private:
    double *arrayToSeparate;
    int arrayToSeparateSize;

    double **result;
    int groupsNumber = 2;
    int groupLength1;
    int groupLength2;

    double **resultBuffer;
    double minDiff;

public:
    DoubleSeparator();
    ~DoubleSeparator();

    double arraySum(double *arr);
    double absoluteValue(double value);
    double *nullify(double *arr);
    double **copyArray(double **arr);

    void userInput();
    void separate();
    void displayResults();
};

DoubleSeparator::DoubleSeparator()
{
    arrayToSeparate = nullptr;
    result = nullptr;

    arrayToSeparateSize = 0;
    groupsNumber = 2;
}

DoubleSeparator::~DoubleSeparator()
{
    for(int i = 0; i < groupsNumber; i++)
    {
        delete[] result[i];
        delete[] resultBuffer[i];

        result[i] = nullptr;
        resultBuffer[i] = nullptr;
    }
    delete[] resultBuffer;
    delete[] result;
    delete[] arrayToSeparate;

    result = nullptr;
    resultBuffer = nullptr;
    arrayToSeparate = nullptr;
}

double DoubleSeparator::absoluteValue(double value)
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

double DoubleSeparator::arraySum(double *arr)
{
    double sum = 0;

    for (int i = 0; i < arrayToSeparateSize; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double **DoubleSeparator::copyArray(double **arr)
{
    double **newArray = new double *[groupsNumber];

    for (int i = 0; i < groupsNumber; i++)
    {
        newArray[i] = new double[arrayToSeparateSize];
        newArray[i] = nullify(newArray[i]);

        for (int j = 0; j < arrayToSeparateSize; j++)
        {
            newArray[i] = arr[i];
        }
    }
    return newArray;
}
double *DoubleSeparator::nullify(double *arr)
{
    for (int i = 0; i < arrayToSeparateSize; i++)
    {
        arr[i] = 0;
    }
    return arr;
}

void DoubleSeparator::userInput()
{
    int size = 2;

    do
    {
        cout << "Enter size of array > 1" << endl;
        cin >> size;

    } while (size < 2);

    this->arrayToSeparateSize = size;
    arrayToSeparate = new double[arrayToSeparateSize];

    for (int i = 0; i < arrayToSeparateSize; i++)
    {
        cout << "Enter element " << i << endl;
        cin >> arrayToSeparate[i];
    }
}

void DoubleSeparator::separate()
{
    minDiff = 100.0;

    resultBuffer = new double *[groupsNumber];

    groupLength1 = 1;
    groupLength2 = arrayToSeparateSize - 1;

    while (groupLength1 < arrayToSeparateSize)
    {
        int arrayToSeparateIndex = 0;

        delete[] result;

        result = new double *[groupsNumber];

        for (int i = 0; i < groupsNumber; i++)
        {
            result[i] = new double[arrayToSeparateSize];
            result[i] = nullify(result[i]);
        }

        for (int i = 0; i < groupLength1; i++)
        {
            result[0][i] = arrayToSeparate[arrayToSeparateIndex];
            arrayToSeparateIndex++;
        }
        for (int i = 0; i < groupLength2; i++)
        {
            result[1][i] = arrayToSeparate[arrayToSeparateIndex];
            arrayToSeparateIndex++;
        }

        double sum1 = (double)arraySum(result[0]);
        sum1 = sum1 - (int)sum1;
        cout << "sum1 = " << sum1 << endl;

        double sum2 = (double)arraySum(result[1]);
        sum2 = sum2 - (int)sum2;
        cout << "sum2 = " << sum2 << endl;

        double diff = absoluteValue(sum1 - sum2);
        cout << "diff = " << diff << endl;

        if (diff < minDiff)
        {
            minDiff = diff;
            resultBuffer = copyArray(result);
            cout << "minDiff: " << (double)minDiff << endl;
        }

        for (int i = 0; i < groupsNumber; i++)
        {
            for (int j = 0; j < arrayToSeparateSize; j++)
            {
                cout << "[" << i << "][" << j << "] = " << result[i][j] << "    ";
            }
            cout << endl;
        }
        cout << "end" << endl;

        groupLength1++;
        groupLength2--;
    }
}

void DoubleSeparator::displayResults()
{
    cout << "ARRAY TO SEPARATE: " << endl;

    for (int i = 0; i < arrayToSeparateSize; i++)
    {
        cout << "[" << i << "] = " << arrayToSeparate[i] << "   ";
    }
    cout << endl;

    cout << "RESULT:" << endl;

    for (int i = 0; i < groupsNumber; i++)
    {
        for (int j = 0; j < arrayToSeparateSize; j++)
        {
            cout << "[" << i << "][" << j << "] = " << resultBuffer[i][j] << "    ";
        }
        cout << endl;
    }

    cout << "minDiff = " << minDiff << endl;
}

int main(int argc, char **argv)
{
    DoubleSeparator separator;
    separator.userInput();
    separator.separate();
    separator.displayResults();
}