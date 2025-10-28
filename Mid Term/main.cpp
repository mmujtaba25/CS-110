#include <iostream>

bool isAccessAllowed(int a, int b, int c);

int main()
{
    int a;
    int b;
    int c;

    std::cout << "Enter the code with spaces between each number: ";
    std::cin >> a >> b >> c;

    if (isAccessAllowed(a, b, c))
    {
        std::cout << "Vault Unlocked!\n";
    }
    else
    {
        std::cout << "Access Denied!\n";
    }

    std::cin.ignore();
    std::cin.get();
    return 0;
}

bool isAccessAllowed(int a, int b, int c)
{
    int pass = a * b;

    if (c % 2 == 0)
        pass += (a + b) % c;
    else
        pass -= std::min(a, std::min(b, c));

    if (pass % 3 == 0)
        return true;

    // pass is not divisible by 3
    return false;
}
