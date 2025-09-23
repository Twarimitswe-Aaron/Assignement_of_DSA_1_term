#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 1, b = 2;

    cout << "Before swap: a=" << a << " b=" << b << endl;
    int *p1 = &a;
    int *p2 = &b;
    swap(p1, p2);
    cout << "After swap: a=" << a << " b=" << b << endl;
    return 0;
}