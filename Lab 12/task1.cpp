#include <iostream>
#include <string.h>

int main()
{
    std::string first_city = "";
    std::string second_city = "";
    std::string third_city = "";

    std::cout << "Enter first city name: ";
    std::getline(std::cin, first_city);
    std::cout << "Enter second city name: ";
    std::getline(std::cin, second_city);
    std::cout << "Enter third city name: ";
    std::getline(std::cin, third_city);

    // compare first and second
    if (second_city < first_city)
        std::swap(first_city, second_city);

    // compare first and third
    if (third_city < first_city)
        std::swap(first_city, third_city);

    // compare second and third
    if (third_city < second_city)
        std::swap(second_city, third_city);

    std::cout << "Cities in alphabetical order: ";
    std::cout << first_city << " - ";
    std::cout << second_city << " - ";
    std::cout << third_city << "\n";

    return 0;
}