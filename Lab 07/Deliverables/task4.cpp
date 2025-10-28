#include <iostream>

// Global variable for tax rate
double taxRate = 0.08; // 8% tax rate

double calculateFinalPrice(double price, int quantity)
{
    double total; // FIX 1: initialize
    double discount = 0.1;
    total = price * quantity * (1 + taxRate) * (1 - discount); // FIX 2: use correct formula
    // FIX 3: remove local `taxRate` variable
    // FIX 4: Remove unneccessay scope

    std::cout << "Debug: Tax rate used: " << taxRate << std::endl;
    return total;
}

int main()
{
    double price = 50.0;
    int quantity = 2;
    double expectedTotal = (price * quantity) * (1 + 0.08) * (1 - 0.1);
    // Expected: 50 * 2 * 1.08 * 0.9 = 97.2

    double result = calculateFinalPrice(price, quantity);
    std::cout << "Total cost for " << quantity << " items at $" << price
              << ": $" << result << std::endl;

    // Test with different values
    price = 100.0;
    quantity = 1;
    expectedTotal = (price * quantity) * (1 + 0.08) * (1 - 0.1); // Expected: 100 * 1 * 1.08 * 0.9 = 97.2
    result = calculateFinalPrice(price, quantity);
    std::cout << "Total cost for " << quantity << " items at $" << price
              << ": $" << result << std::endl;

    return 0;
}