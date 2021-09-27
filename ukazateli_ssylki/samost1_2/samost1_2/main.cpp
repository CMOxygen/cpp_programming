#include <iostream>

using namespace std;

int main()
{
    int value = 3;
    cout << "Value: " << value << endl;

    int* firstPointer = nullptr;
    cout << "First Pointer:    " << firstPointer << endl;

    firstPointer = &value;
    cout << "FirstPointer = value:    " << firstPointer << endl;

    int* secondPointer = nullptr;
    cout << "Second Pointer:    " << secondPointer << endl;

    secondPointer = &value;
    cout << "SecondPointer = value:    " << secondPointer << endl;

    int* thirdPointer = nullptr;
    cout << "Third Pointer:    " << thirdPointer << endl;

    thirdPointer = &value;
    cout << "ThirdPointer = value:    " << thirdPointer << endl;

    *firstPointer = 5;
    cout << "FirstPointer = 5:    " << firstPointer << "    value:  " << value << endl;

    *secondPointer = 8;
    cout << "SecondPointer = 8:    " << secondPointer << "    value:  " << value << endl;

    *thirdPointer = 12;
    cout << "ThirdPointer = 12:    " << thirdPointer << "    value:  " << value << endl;

    return 0;
}
