#include <iostream>

using namespace std;

int main()
{
    //объ€вл€ем константу
    const int a = 3;

    int *pA;
    //    *pA = &a; не скомпилируетс€, если раскомментировать

    //а константному указателю будет по кайфу
    const int *pB;
    pB = &a;
    pB = nullptr;

    cout << a << "  " << pB << endl;

    return 0;
}
