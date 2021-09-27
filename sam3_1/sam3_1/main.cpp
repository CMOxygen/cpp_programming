#include <iostream>

/*
    �������� ����� �������,
    ������� ������� 3�4,
    �������� ������ ������������� ��������� ������ 3�4
    ����� ������� ����� 3 � 4
    ������ ���� ����������� ������� �������� ������� ��� ���������, ������� � ���� ����� ��������,
    ����� ��� ������ ������� �� �����,
    ����� ��� ��������� �������� ������ �������� ������� ������� �� ������ ������������.
*/
/* ��:
    �������� �����,
    ����� ��������� ������������ �����,
    � �������� ������ 3 ����� ���: ����� �����, ��������� ������� �����, �����������,
    ����������� ������ ���������������� ��� �����: ��������� = 0, �������� = 1, ��� ���� = 0.
    ������:
    ����� ��� ������ ����� �� �����,
    ����� ��� ����� ����� � ����������, �������������� ����� 0 � ����� ��������, ����� �� ������ ����������� �����(��������� �� � ����������� ����).
    1 ��� 6/3 = 3 ��� 0/1.
    ���� ����� ������ ����� �����., �� ����� - ����� ����� ������.
*/
using namespace std;

class SuperArray
{
private:
    static const int width = 4;
    static const int heigth = 3;
    int arrayValues[heigth][width] = {0};

public:
    SuperArray(int newArray[heigth][width]);
    ~SuperArray();

    void changeElement();
    void changeElement(int x, int y, int value){ arrayValues[x][y] = value; }
    void display();
};

SuperArray::SuperArray(int newArray[heigth][width])
{
    for(int i = 0; i < this->heigth; i++)
    {
        for(int j = 0; j < this->width; j++)
            arrayValues[i][j] = newArray[i][j];
    }
    display();
}

SuperArray::~SuperArray()
{

}

void SuperArray::display()
{
    for(int i = 0; i < heigth; i++)
    {
        for(int j = 0; j < width; j++)
            cout << "array[" <<i << "]["<< j << "] = " << arrayValues[i][j] << "     ";

        cout << endl;
    }
}

void SuperArray::changeElement()
{
    int x;
    int y;
    int newValue;

    cout << "Enter number of row.." << endl;
    cin >> x;
    cout << "Enter number of column.." << endl;
    cin >> y;
    cout << "Enter new value of the element.." << endl;
    cin >> newValue;

    if(x > heigth || y > width)
    {
        cout << "Too high values" << endl;
        return;
    }

    arrayValues[x][y] = newValue;
}
using namespace std;

int main()
{
    int array1[3][4] = {{1,2,3,4},
        {5,6, 7, 8},
        {9, 0, 1,2}
    };

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
            cin >> array1[i][j];
    }

    SuperArray super(array1);

    super.changeElement();
    super.changeElement(1, 1, 20);

    super.display();

    return 0;
}
