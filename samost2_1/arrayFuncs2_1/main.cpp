#include <iostream>

using namespace std;

void doSmth(int inArray[]);

int main()
{
    int arr[4] = {1,2,3,4};
    doSmth(arr);

    return 0;
}

void doSmth(int inArray[])
{
    cout << sizeof(inArray) << endl;

    for(int i = 0; i < 4; i++)
        cout << inArray[i] << endl;
}
