#include <iostream>

void swapNumbers(int *a, int *b);

int main()
{
    int x = 15;
    int y = 30;

    std::cout << "Before: x = " << x << ", y = " << y << "\n";

    swapNumbers(&x, &y);

    std::cout << "After: x = " << x << ", y = " << y << "\n";

    return 0;
}

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
