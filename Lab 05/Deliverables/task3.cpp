#include <iostream>
#include <math.h>

bool isPrime(int number, bool &primeError);

int main()
{
    int count;

    std::cout << "Print how many numbers you will enter: ";
    std::cin >> count;

    int number; // the number
    bool primeError = false; // is error detected
    while (count > 0)
    {
        count--;

        std::cout << "Enter a postiive non zero number: ";
        std::cin >> number;
        if (isPrime(number, primeError))
        {
            std::cout << "You entered a prime number.\n";
            break;
        }

        if (primeError)
        {
            std::cout << "You entered an invalid number.\n";
        }
    }

    if (count <= 0)
    {
        std::cout << "You ran out of tries.\n";
    }

    // ignore previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}

bool isPrime(int number, bool &primeError)
{
    // if number is negative or zero then set primeError to true
    if (number <= 0)
    {
        primeError = true;
        return false;
    }

    if (number == 1 || number == 2)
    {
        return true;
    }

    primeError = false;
    for (int i = 2; i < std::ceil(number / 2.f); i++)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}
