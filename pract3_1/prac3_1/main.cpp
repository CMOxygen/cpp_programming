#include <iostream>

using namespace std;

int main()
{
    //��������� ���������
    const int a = 3;

    int *pA;
    //    *pA = &a; �� ��������������, ���� �����������������

    //� ������������ ��������� ����� �� �����
    const int *pB;
    pB = &a;
    pB = nullptr;

    cout << a << "  " << pB << endl;

    return 0;
}
