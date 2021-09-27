#include <iostream>
/*
�������� ���������, � ������� ����� �������� ������ �� 10 ���������
�������������� ���� ����� �������� ������ �� 20 ��������� �������������� ����.
1. �������� �������, ������� �������� � ���������� ���������� ������� �������.
2. �������� �������, �������, ��������� ������ �� 1 �������, �������� ������ ������ �� ����. ���������:
    �) ������ ������ ������� ������� ������ ��������� ����� ���� �������� ���� 1-�� �������� 1-�� �������.
    �) ������ ������� ������� ������� ������ ��������� ����� ���� ������ ���� 1-�� �������� 1-�� �������.
    �) ������ � ��������� ������� ������� ������ - �� �� �����, ������ ��� ���� ������� �������� ������� �������.
    �) ������ ������ ��� ������ ������� �������, ������ ��� ������ ������� �������.

    ������� ����� ������� � ������ �������, ������������� ���������, ��������� ���������� ���������� ����� iostream
*/

bool isEven(int value) { return value % 2 == 0; }

int sumOfOdds(int value);
int sumOfEvens(int value);

void displayArray(int arrayToDisplay[], const int size);

using namespace std;

int main(int argc, char **argv)
{
    const int size1 = 10;
    const int size2 = 20;

    int array1[size1] = {0};
    int array2[size2] = {0};

    cout << "Enter elements for the array1[10]" << endl;
    for (int i = 0; i < size1; i++)
        cin >> array1[i];

    for (int i = 0; i < size2; i++)
    {
        if (isEven(i))
        {
            array2[i] = sumOfEvens(array1[i / 2]);
            cout << "Sum of even numebrs in array1[" << i / 2 << "] element: " << array2[i] << endl;
        }
        else
        {
            array2[i] = sumOfOdds(array1[i / 2]);
            cout << "Sum of odd numebrs in array1[" << i / 2 << "] element: " << array2[i] << endl;
        }
    }
    cout << endl;

    cout << "array1 values:" << endl;
    displayArray(array1, size1);

    cout << "array2 values:" << endl;
    displayArray(array2, size2);
}

int sumOfEvens(int value)
{
    int result = 0;

    while (value > 0)
    {
        int digit = value % 10;

        if (isEven(digit))
            result += digit;

        value /= 10;
    }
    return result;
}

int sumOfOdds(int value)
{
    int result = 0;

    while (value > 0)
    {
        int digit = value % 10;

        if (!isEven(digit))
            result += digit;

        value /= 10;
    }
    return result;
}

void displayArray(int arrayToDisplay[], const int size)
{
    for (int i = 0; i < size; i++)
        cout << "[" << i << "]: " << arrayToDisplay[i] << "    ";

    cout << endl;
}
