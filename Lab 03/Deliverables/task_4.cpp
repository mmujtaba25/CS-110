#include <iostream>

int main()
{
    float annualSales;
    float bonus;

    std::cout << "Enter Annual Sales: $";
    std::cin >> annualSales;
    std::cout << "\n";

    if (annualSales >= 15'000)
    {
        bonus = annualSales * (2.f / 100);
    }
    else
    {
        bonus = annualSales * (1.5f / 100);
    }

    std::cout << "Bonus: $" << bonus << "\n";

    // ignore is used to clear previous inputs from user
    std::cin.ignore();
    std::cin.get();
    return 0;
}