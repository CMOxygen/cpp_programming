#include <iostream>

/*
    Конструrтор
*/

using namespace std;

class A
{
private:
    int x;
    int y;

public:
    A(int i, int j) : x(i), y(j) { cout << x << " " << y << endl; }
};

int main(int argc, char **argv)
{
    A object(3, 4);
}