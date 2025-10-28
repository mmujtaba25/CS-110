#include <iostream>

#define PRINT(stream) std::cout << stream << std::endl;

void defTestA(int a, int b, int c = 0)
{
    PRINT(a);
    PRINT(b);
    PRINT(c);
    PRINT("---");
}
// void defTestB(int a, int b = 1, int c) FAIL: cannot have default parameter in center, can only be at last
// {
//     PRINT(a);
//     PRINT(b);
//     PRINT(c);
//     PRINT("---");
// }
void defTestC(int a = 0, int b = 0, int c = 0)
{
    PRINT(a);
    PRINT(b);
    PRINT(c);
    PRINT("---");
}

int main()
{
    defTestA(1, 2, 3);
    defTestA(1, 2);
    defTestA(1, 2, 3);
    // defTestB(1, 2, 3);
    // defTestB(1, 3);  FAIL: cannot have default parameter in center, can only be at last
    defTestC();

    std::cin.ignore();
    std::cin.get();
    return 0;
}