#include <iostream>
using namespace std;

int main()
{
    char ch;
    char *ptr = nullptr;
    char **pptr = nullptr;
    ptr = &ch;
    pptr = &ptr;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "You entered: " << **pptr << endl;
    cout << "You entered: " << *ptr << endl;
    cout << "Address of ch: " << (void *)&ch << endl;
    cout << "Address of ptr: " << (void *)*pptr << endl;

    return 0;
}