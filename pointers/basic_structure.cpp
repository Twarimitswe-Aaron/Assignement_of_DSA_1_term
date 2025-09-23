#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};
int main()
{
    Point point = {1, 2};
    Point *ptr = nullptr;
    ptr = &point;
    cout << "Before: (" << ptr->x << "," << ptr->y << ")" << endl;
    ptr->x = 10;
    ptr->y = 20;
    cout << "After: (" << ptr->x << "," << ptr->y << ")" << endl;

    return 0;
}