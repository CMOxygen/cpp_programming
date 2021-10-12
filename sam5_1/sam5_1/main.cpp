#include <iostream>

using namespace std;

/*
������� �����
����������� ������ ��������
���������� ������ �������
2 ������:
1 ����� ��� �������� � ����������.
2 ����� ��� ������ �� �����.
������ �������������.

����� ��������� ������ �������� �� ����� ����� �� ��������� ����� ������� �� ������ ���������� � ����������.
������ ����� ��������� �������� ����� ������� ������� ����� �� ������ ���������� � ����������.
*/

/*��
�������� ��������� � �� �����.
��������� ������ ����������� � ���������� ������ ����� �����,
����������� ���-�� ������, �� ������� ���� �������� ���, ����� �����, ������ ������ ������ �� ������ ���-�� ������
����� �������, ����� ����� ��������� ������ ���� ����������� ������ � ���� �����
(�������� �������� - ����������� ������� ����� ����� ������� � ����� ��������� ������.).
*/

class Array
{
protected://protected ��� �������� ������ �����������

    int *workArray;
    int arraySize = 0;

private:

public:
    Array();
    ~Array();

    void userInput();
    void displayArray();
};

class ArrayManager : public Array
{
public:
    ArrayManager();
    ~ArrayManager();

    void displayElement();
    void changeElement();
};

Array::Array()
{
    this->workArray = nullptr;
    this->arraySize = 0;
}

Array::~Array()
{
    delete[] this->workArray;
}

void Array::userInput()
{
    int size = 1;

    do
    {
        cout << "Enter size of array > 0" << endl;
        cin >> size;
    }
    while (size <= 0);

    this->arraySize = size;
    this->workArray = new int(arraySize);

    for(int i = 0; i < arraySize; i++)
    {
        cout << "Enter element " << i << " of array:" << endl;
        cin >> this->workArray[i];
    }
}

void Array::displayArray()
{
    for(int i = 0; i < this->arraySize; i++)
        cout << "Element "<< i << " = " << workArray[i] << endl;
}

ArrayManager::ArrayManager()
{

}

ArrayManager::~ArrayManager()
{

}

void ArrayManager::displayElement()
{
    int index = 1;

    do
    {
        cout << "Enter number of element TO WATCH > 0" << endl;
        cin >> index;
    }
    while (index <= 0);

    cout << "Element " << index << " = " << Array::workArray[index] << endl;
}
void ArrayManager::changeElement()
{
    int index = 1;
    int value = 0;

    do
    {
        cout << "Enter number of element TO CHANGE > 0" << endl;
        cin >> index;
    }
    while (index <= 0);

    do
    {
        cout << "Enter new value for element > 0" << endl;
        cin >> value;
    }
    while (value < 0);

    Array::workArray[index] = value;
}

int main()
{
    ArrayManager mngr;
    mngr.userInput();
    mngr.displayArray();

    mngr.displayElement();
    mngr.changeElement();
    mngr.displayArray();

    return 0;
}
