#include <iostream>
#include <iomanip>

int main()
{
    double monthlyPayment = 1345.4567;
    double totalPayment = 866.887234;

    std::cout << std::setprecision(7); // will not work; requieres fixed
    std::cout << monthlyPayment << std::endl;
    std::cout << totalPayment << std::endl;
    std::cout << std::fixed << std::setprecision(2); // will work now
    // all subsequent print statements printing float will be rounded down to two decimal places
    std::cout << std::setw(8) << monthlyPayment << std::endl;
    std::cout << std::setw(8) << totalPayment << std::endl;
    std::cout << std::left; // all subsequent print statements will be aligned to left
    std::cout << std::setw(8) << monthlyPayment << std::endl;
    std::cout << std::setw(8) << totalPayment << std::endl;
    std::cout << std::right; // all subsequent print statements will be aligned to right
    std::cout << std::setw(8) << monthlyPayment << std::endl;
    std::cout << std::setw(8) << totalPayment << std::endl;

    std::cin.ignore();
    std::cin.get();
    return 0;
}