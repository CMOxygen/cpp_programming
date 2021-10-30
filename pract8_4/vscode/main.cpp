#include <iostream>

using namespace std;

/*  1. Написать программу, которая находит определенный интеграл функции y = x^2*0,01 + 1
 *  Границы интегрирования программа должна запрашивать с клавиатуры и шаг тоже должна запрашивать с клавиатуры.
 *  Задача должна решаться в стиле ООП.
 * 
 *  2. С клавиатуры вводится массив вещественных чисел, эти числа нужно поделить на две группы таким образом, 
 *  чтобы дробная часть суммы чисел и в первой и во второй группе была минимальна. Повторы запрещены.
 *  
 *  Массив из 4 чисел {5.5, 3.5, 1.7, 21.4} 
 *  1: 9.0
 *  2: 23.1
 */

class A;
class B;

class A
{
private:
    int x;

public:
    A(int i) : x(i) { cout << "CONSTRUCTOR A" << endl; }
    ~A() { cout << "DESSTRUCTOR A" << endl; }

    friend B;
};

class B
{
private:
    int y;

public:
    B(int i) : y(i) { cout << "CONSTRUCTOR B" << endl; }
    ~B() { cout << "DESSTRUCTOR B" << endl; }

    void equation(A &obA)
    {
        if (y > obA.x)
            cout << "class B > class A" << endl;
        if (y < obA.x)
            cout << "class B < class A" << endl;
        if (y == obA.x)
            cout << "class B == class A" << endl;
    }
};

int main(int argc, char **argv)
{
    A ob1(3);
    B ob2(4);

    ob2.equation(ob1);
}