#include <iostream>

/*
    написать класс,
    класс реализует обыкновенную дробь,
    в качестве данных 3 числа int: целая часть, числитель дробной части, знаменатель,
    конструктор должен инициализировать эти числа: числитель= 0, знаменатель = 1, целая часть = 0.
    Методы:
    метод для вывода дроби на экран,
    метод для ввода дроби с клавиатуры, предотвращения ввода 0 и отриц. знаменатель, также он должен обрабатыdать дробь(приводить ее к правильному виду).
    1 цел 6/3 = 3 цел 0/1.
    Если хотим ввести отриц. число., то будет - перед целой частью.
 */

using namespace std;

class Fraction
{
    int numerator = 0;
    int denominator = 0;
    int integerPart = 0;

public:
    Fraction();
    Fraction(int newNumerator, int newDenominator, int newIntegerPart);
    Fraction(int newNumerator, int newDenominator);
    ~Fraction();

    Fraction userInput();

    void displayFraction();
    void simplifyFraction();

    int getAbs(int value);
};

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
    integerPart = 0;
}

Fraction::Fraction(int newIntegerPart, int newNumerator, int newDenominator)
{
    numerator = newNumerator;
    denominator = newDenominator;
    integerPart = newIntegerPart;
}

Fraction::Fraction(int newNumerator, int newDenominator)
{
    numerator = newNumerator;
    denominator = newDenominator;
}

Fraction::~Fraction()
{
}

int Fraction::getAbs(int value)
{
    if (value >= 0)
    {
        return value;
    }
    else
    {
        return (-1) * value;
    }
}

void Fraction::simplifyFraction()
{
    bool simplified = false;
    int maxValue = 1;
    int prevValue = 0;

    int absIntegerPart = getAbs(integerPart);
    int absNumerator = getAbs(numerator);

    absNumerator += absIntegerPart * denominator;

    while (true)
    {
        maxValue = absNumerator;

        if (maxValue < denominator)
            maxValue = denominator;

        for (int i = 1; i < maxValue; i++)
        {
            if (absNumerator % i == 0 && denominator % i == 0)
            {
                absNumerator /= i;
                denominator /= i;
            }
        }
        if (maxValue == absNumerator || maxValue == denominator)
            break;
    }

    if (absNumerator * absNumerator > denominator * denominator)
    {
        absIntegerPart = absNumerator / denominator;
        absNumerator = absNumerator % denominator;
    }
    else
    {
        absIntegerPart = 0;
    }

    if (numerator > 0)
    {
        numerator = absNumerator;
    }
    else
    {
        numerator = (-1) * absNumerator;
    }

    if (integerPart > 0)
    {
        integerPart = absIntegerPart;
    }
    else
    {
        integerPart = (-1) * absIntegerPart;
    }
}

Fraction Fraction::userInput()
{
    int userInt = 0;
    int userNum = 0;
    int userDenum = 0;

    cout << "Enter integer part of Fraction" << endl;
    cin >> userInt;

    cout << "Enter numinator of Fraction" << endl;
    cin >> userNum;

    while (userDenum == 0 || userDenum < 0)
    {
        cout << "Enter denomominator of Fraction" << endl;
        cin >> userDenum;

        if (userDenum == 0 || userDenum < 0)
            cout << "Denominator can't be equal or lower than 0" << endl;
    }

    Fraction userFraction(userInt, userNum, userDenum);
    userFraction.simplifyFraction();

    return userFraction;
}

void Fraction::displayFraction()
{
    cout << "Fraction: " << endl;

    if (integerPart < 0 || numerator < 0)
        cout << "-";

    if (integerPart != 0)
        cout << getAbs(integerPart);

    if (numerator != 0)
        cout << " " << getAbs(numerator) << "/" << getAbs(denominator) << endl;

    if (integerPart == 0 && numerator == 0)
        cout << 0 << endl;
}

int main(int argc, char **argv)
{
    Fraction fract = fract.userInput();
    fract.displayFraction();

}
