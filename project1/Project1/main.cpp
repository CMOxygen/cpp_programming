#include <iostream>

//написать программу которая запрашивает с клавиатуры массив из 16 целых чисел, после чего создает двумерный массив 4х4
//и заполняет его числами из введенного масива по возрастанию от элемента (0,0) к элементу (3,3) змейкой.

using namespace std;

int main()
{
    const int size = 4;

    int arr[size][size] = {0};
    int anotherArr[size][size] = {0};
    int arr2[size * size] = {0};
    int sorted[size * size] = {0};

    int min = 10000;
    int minNum;

    for(int i = 0; i < size*size; i++)
    {
        cin >> arr2[i];

        if(arr2[i] < min){
            min = arr2[i];
            minNum = i;
        }
    }
    cout << "min: " << min << endl;
    sorted[0] = min;

    for(int i = 0; i < size*size; i++)
    {
        for(int j = 1; j < size*size; j++)
        {

        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
