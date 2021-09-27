#include <iostream>

/*
    написать класс матрицы,
    размеры матрицы 3х4,
    качестве данных предусмотреть двумерный массив 3х4
    также размеры конст 3 и 4
    должен быть конструктор который заполнит матрицу тем значением, которое в него будет передано,
    метод дл€ вывода матрицы на экран,
    метод дл€ изменени€ значени€ одного элемента матрицы элемент по выбору пользовател€.
*/
/* ƒ«:
    написать класс,
    класс реализует обыкновенную дробь,
    в качестве данных 3 числа инт: цела€ часть, числитель дробной части, знаменатель,
    конструктор должен инициализировать эти числа: чилистель = 0, знаменат = 1, цел чать = 0.
    ћетоды:
    метод дл€ вывода дроби на экран,
    метод дл€ ввода дроби с клавиатуры, предотвращени€ ввода 0 и отриц знаменат, также он должен обрабатыать дробь(приводить ее к правильному виду).
    1 цел 6/3 = 3 цел 0/1.
    ≈сли хотим ввести отриц число., то будет - перед целой частью.
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
