#include <iostream>
#include <random>
#include <iomanip>
#include <sstream>
#include <string>

int getRandomPrintableChar(int minInclusive, int maxInclusive);
std::string getStringOfCharNTimes(char character, size_t times);
void printRow(const std::string &first, const std::string &second, const std::string &third);

int main()
{
    constexpr size_t ARRAY_SIZE = 10;
    int array[ARRAY_SIZE];

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = getRandomPrintableChar(1, 100);
    }

    printRow("Element", "Value", "Histogram");
    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        printRow(std::to_string(i), std::to_string(array[i]), getStringOfCharNTimes('*', array[i]));
    }

    std::cout << "\n";
    return 0;
}

int getRandomPrintableChar(int minInclusive, int maxInclusive)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(minInclusive, maxInclusive);
    return distrib(gen);
}

std::string getStringOfCharNTimes(char character, size_t times)
{
    std::stringstream string_;
    for (size_t i = 0; i < times; i++)
    {
        string_ << character;
    }
    return string_.str();
}

void printRow(const std::string &first, const std::string &second, const std::string &third)
{
    constexpr size_t SPACING = 12;
    std::cout << std::left << std::setw(SPACING) << first
              << std::left << std::setw(SPACING) << second
              << std::left << std::setw(SPACING) << third
              << "\n";
}