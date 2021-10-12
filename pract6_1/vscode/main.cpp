#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int **arr = nullptr;

    const int width = 6;
    const int height = 4;

    arr = new int *[height];

    for (int i = 0; i < height; i++)
    {
        arr[i] = new int[width];

        for (int j = 0; j < width; j++)
            arr[i][j] = j + 1;
    }

    for (int i = 0; i < height; i++)
    {
        cout << i << ":" << endl;

        for (int j = 0; j < width; j++)
        {
            cout << "[" << i << "][" << j << "] = " << arr[i][j] << "    ";
        }
        cout << endl;
    }

    for (int i = 0; i < height; i++)
        delete[] arr[i];

    delete[] arr;
    arr = nullptr;
}