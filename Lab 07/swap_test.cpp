#include <iostream>

void swapV(int x, int y)
{
    int s;
    s = x;
    x = y;
    y = s;
}

void swapR(int &x, int &y)
{
    int s;
    s = x;
    x = y;
    y = s;
}

int main()
{
    int x = 4;
    int y = 5;

    std::cout << "Orignal: " << x << ", " << y << std::endl;
    swapV(x, y);
    std::cout << "Pass by Value: " << x << ", " << y << std::endl;
    swapR(x, y);
    std::cout << "Pass by Reference: " << x << ", " << y << std::endl;

    std::cin.ignore();
    std::cin.get();
    return 0;
}