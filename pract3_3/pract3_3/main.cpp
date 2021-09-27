#include <iostream>

using namespace std;

class A
{
private:
    int x, y;

public:
    int getX(){ return this->x; }
    void setX(int newValue){ this->x = newValue; }

    int getY(){ return this->y; }
    void setY(int newValue){ this->y = newValue; }
};

int main()
{
    A object;

    object.setX(5);
    object.setY(10);

    cout << "object.x = " << object.getX() << endl;
    cout << "object.y = " << object.getY() << endl;

    return 0;
}
