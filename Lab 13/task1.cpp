#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *p = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value stored in pointer p: " << p << endl;
    cout << "Value using dereferencing *p: " << *p << endl;

    return 0;
}
