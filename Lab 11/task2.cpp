#include <iostream>

int sumDigits(int number)
{
    // return if no digits left
    if (number == 0)
        return 0;

    // add last digit; truncate last digit using int casting; call recursively
    return (number % 10) + sumDigits(number / 10);
}

int main()
{
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    std::cout << "Sum of digits: " << sumDigits(number) << "\n";

    return 0;
}