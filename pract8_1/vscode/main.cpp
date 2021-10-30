#include <iostream>

/*
В данном примере рассмотрена возможность запрета копирования.
*/

using namespace std;

const int K = 10;

class DinArr
{
private:
    int *arr;
    int arrSize;

public:
    DinArr(const DinArr &ob);
    DinArr(int x)
    {
        arrSize = K;
        arr = new int[arrSize];

        for (int i = 0; i < arrSize; i++)
            arr[i] = x;
    }
    ~DinArr() { delete[] arr; }

    DinArr &operator=(const DinArr &ob);

    void show()
    {
        for (int i = 0; i < arrSize; i++)
            cout << "   " << arr[i];

        cout << endl;
    }
};

int main(int argc, char **argv)
{
    DinArr arr1(1), arr2(2);

    cout << "\n ARRAY1:" << endl;
    arr1.show();

    cout << "\n ARRAY2:" << endl;
    arr2.show();

    // UNDEFINED REFERENCE
    // DinArr arr3 = arr1;
    // arr2 = arr3;

    //NO OPERATOR +
    // arr1 = arr1 + arr2;
}