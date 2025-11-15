#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>

#define PRINT_LINE(message) std::cout << message << "\n"

unsigned char getRandomPrintableChar();

int main()
{
    constexpr size_t ARRAY_SIZE = 10;
    unsigned char array[ARRAY_SIZE];

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = getRandomPrintableChar();
    }

    int lowerCaseCount = 0;
    int upperCaseCount = 0;
    int digitCount = 0;
    int specialCount = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << "_";
        if (islower(array[i]))
            lowerCaseCount++;
        else if (isupper(array[i]))
            upperCaseCount++;
        else if (isdigit(array[i]))
            digitCount++;
        else
            specialCount++;
    }
    std::cout << "\n\n";

    PRINT_LINE(upperCaseCount << " Upper Case Characters Count");
    PRINT_LINE(lowerCaseCount << " Lower Case Characters Count");
    PRINT_LINE(digitCount << " Digits Count");
    PRINT_LINE(specialCount << " Special Characters Count");

    return 0;
}

unsigned char getRandomPrintableChar()
{
    auto getRandomChar = []() -> unsigned char
    {
        // static to reduce overhead by calling continously
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(0, 255);
        return distrib(gen);
    };

    unsigned char randomChar = getRandomChar();
    // get a random characgter until
    while (!isprint(randomChar))
    {
        randomChar = getRandomChar();
    }

    return randomChar;
}
