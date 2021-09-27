#include <iostream>

using namespace std;

class A
{
private:
    int x;

public:
    int y;
};

int main()
{
    A ob1, ob2;
    ob1.y = 3;
    ob2.y = 7;

//    ob1.x = 2; не получится тк. Х - private
//    ob2.x = 5; не получится тк. Х - private

    cout << ob1.y << "  " << ob2.y << endl;
    return 0;
}
