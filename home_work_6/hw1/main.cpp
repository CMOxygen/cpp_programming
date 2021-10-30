#include <iostream>

using namespace std;

/*  1. Написать программу, которая находит определенный интеграл функции y = x^2 * 0,01 + 1 
 *  Границы интегрирования программа должна запрашивать с клавиатуры и шаг тоже должна запрашивать с клавиатуры.
 *  Задача должна решаться в стиле ООП.
 */

class Integral
{
private:
    double **table;

    double result;
    double step;

    int lowerBorder;
    int upperBorder;

    int valuesCount = 3;

    double intervalsNumber;

public:
    Integral();
    ~Integral();

    void userInput();
    void displayResult();
    void integrate();
    void nullify();

    double getSquare(double value) { return value * value; }
};

Integral::Integral()
{
    table = nullptr;
    result = 0;
    step = 0;
    lowerBorder = 0;
    upperBorder = 0;
    intervalsNumber = 0;
}

Integral::~Integral()
{
    for (int i = 0; i < this->valuesCount; i++)
    {
        delete table[i];
        table[i] = nullptr;
    }
    delete[] table;
    table = nullptr;
}

void Integral::nullify()
{
    for (int i = 0; i < valuesCount; i++)
    {
        for (int j = 0; j <= intervalsNumber; j++)
        {
            this->table[i][j] = 0;
        }
    }
}

void Integral::userInput()
{
    cout << "Enter lower border of integral:" << endl;
    cin >> this->lowerBorder;

    cout << "Enter upper border of integral:" << endl;
    cin >> this->upperBorder;

    cout << "Enter integration step:" << endl;
    cin >> this->step;

    this->intervalsNumber = (upperBorder - lowerBorder) / step;
    cout << "Intervals number: " << this->intervalsNumber << endl;

    this->table = new double *[this->valuesCount];

    for (int i = 0; i < this->valuesCount; i++)
    {
        this->table[i] = new double[(int)this->intervalsNumber];
    }
    nullify();
}

void Integral::displayResult()
{
    for (int i = 0; i < this->valuesCount; i++)
    {
        for (int j = 0; j <= this->intervalsNumber; j++)
        {
            cout << "[" << i << "][" << j << "] = " << this->table[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "Result: " << result << endl;
}

void Integral::integrate()
{
    double sum = 0;

    for (int i = 0; i < valuesCount; i++)
    {
        for (int j = 0; j <= intervalsNumber; j++)
        {
            this->table[0][j] = this->step * j;
            this->table[1][j] = 1 / (1 + getSquare(table[0][j]));
        }
    }
    for (int i = 1; i < intervalsNumber; i++)
    {
        sum += this->table[1][i];
    }
    result = step * ((table[1][0] + table[1][(int)intervalsNumber]) / 2 + sum);
}

int main(int argc, char **argv)
{
    Integral integral;

    integral.userInput();
    integral.integrate();
    integral.displayResult();
}