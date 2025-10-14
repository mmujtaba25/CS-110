#include <iostream>
#include <iomanip>

#include <math.h> // for M_PI
#include <cmath>

double areaOfPentagon(double radius);

int main()
{
    float number;
    std::cout << "Enter the length from the centre to a vertex: ";
    std::cin >> number;

    std::cout << "The area of pentagon is " << std::fixed << std::setprecision(2) << areaOfPentagon(number) << "\n";

    std::cin.ignore();
    std::cin.get();
    return 0;
}

double areaOfPentagon(double radius)
{
    // M_PI is from math.h

    // get side from radius using formula
    double side = 2 * radius * std::sin(M_PI / 5);
    // from calculate size, calculate and return area
    return (5 * std::pow(side, 2)) / (4 * std::tan(M_PI / 5));
}
