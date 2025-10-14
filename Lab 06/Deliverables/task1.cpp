#include <iostream>
#include <cmath>

int main()
{
    // predefined constants
    // will be optimzed away by compiler since constexpr
    constexpr double PI = 3.14159;
    constexpr double E = 2.71828;

    // some functions defined in "cmath" header file
    std::cout << "sqrt(4.0): " << std::sqrt(4.0) << "\n";
    std::cout << "floor(-2.5: " << std::floor(-2.5) << "\n";
    std::cout << "sin(2*PI): " << std::sin(2 * PI) << "\n";
    std::cout << "asin(0.5): " << std::asin(0.5) << "\n";
    std::cout << "cos(2*PI): " << std::cos(2 * PI) << "\n";
    std::cout << "acos(0.5): " << std::acos(0.5) << "\n";
    std::cout << "pow(2.0,2): " << std::pow(2.0, 2) << "\n";
    std::cout << "atan(1.0): " << std::atan(1.0) << "\n";
    std::cout << "log(E): " << std::log(E) << "\n";
    std::cout << "ceil(-2.5): " << std::ceil(-2.5) << "\n";
    std::cout << "exp(1.0): " << std::exp(1.0) << "\n";
    std::cout << "floor(2.5): " << std::floor(2.5) << "\n";
    std::cout << "max(2,std: " << std::max(2, std::min(3, 4)) << "\n";
    std::cout << "log10(10.0): " << std::log10(10.0) << "\n";
    std::cout << "sqrt(125.0): " << std::sqrt(125.0) << "\n";
    std::cout << "pow(2.0, 3):" << std::pow(2.0, 3) << "\n";

    return 0;
}