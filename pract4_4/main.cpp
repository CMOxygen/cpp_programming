#include <iostream>

using namespace std;

/* ДЗ

    Написать программу, которая запрашивает с клавиатуры массив целых чисел и его размер,
    после чего, делит его на 3 части(создает 3 новых массива).
    поделить необходимо так, чтобы суммы элементов получившихся частей различались минимально.
    Реализовать в объектно-ориентированном стиле, для этого, написать класс.
    В качестве данных указатели, размеры массива и др. необ. параметры и данные.
    В качестве методов:
        Конструктор инициализирующий указатели и размеры массивов нулями,
        Деструктор, освобождающий память(как шаблон см. практ4_3).

    Методы:
        метод для создания массива(пользовательский ввод). (*обесп. возможность перезаписи).
        метод оптималаьно делящий основой массив на 3 части, он же создает 3 производных массива,
            заполнив их элементами.
        метод для вывода результатов на экран.(1 массива, 3 получившихся и макс. разность)

    Доп. условие:
        Обеспечить корректность работы, в случае, если методы будут вызываться не по порядку.
            (просто не должны работать).

    Дружественный интерфейс.
    Дополнительным библиотеками пользоваться нельзя.
*/

class DM
{
private:
    int *Mas;
    int K;

public:
    //кноструктор инициализирует данные нулями для безопасности
    DM()
    {
        Mas = nullptr;
        K = 0;
    }
    //деструктор освобождает память
    ~DM() { delete[] Mas; }
};

int main(int argc, char **argv)
{
    DM dm;

    return 0;
}