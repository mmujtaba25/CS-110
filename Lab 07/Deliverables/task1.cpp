#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

struct Range
{
    float min;
    float max;

    // get min and max of data type
    static Range getDefault()
    {
        return Range{std::numeric_limits<float>::min(), std::numeric_limits<float>::max()};
    }
};

// FUNCTIONS PROTOTYPES

float monthly_payment(float loan_amount, float annual_interest_rate, int number_of_payments = 12);
// struct is used so user needs to either define both min and max or none at all; to reduce clutter
float input(const std::string &message, Range range = Range::getDefault());

// MAIN

int main()
{
    float loan_amount = input("Loan Amount", {0.0f, 1000000.0f});
    float annual_interest_rate = input("Annual Interest Rate", {0.0f, 100.0f});
    float number_of_payments = input("Number Of Payments", {1.0f, 600.0f}); // up to 50 years

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Monthly Payment: "
              << monthly_payment(loan_amount, annual_interest_rate, number_of_payments)
              << '\n';

    // test with default test cases
    std::cout << "CASE 1: " << monthly_payment(100000, 12, 12) << '\n';
    std::cout << "CASE 2: " << monthly_payment(500000, 10, 60) << '\n';
    std::cout << "CASE 3: " << monthly_payment(100000, 12) << '\n';
    std::cout << "CASE 4: " << monthly_payment(10000, 12) << '\n';

    std::cin.ignore();
    std::cin.get();
    return 0;
}

// FUNCTIONS DECLERATIONS

float monthly_payment(float loan_amount, float annual_interest_rate, int number_of_payments)
{
    // calculate monthly rate
    const float monthly_rate = annual_interest_rate / (12 * 100);
    // substituiting into formula
    return (monthly_rate * loan_amount) / (1 - std::pow(1 + monthly_rate, -number_of_payments));
}

float input(const std::string &message, Range range)
{
    float result = -1;
    std::cout << message << ": ";

    while (true)
    {
        std::cin >> result;
        // stopping the program from going crazy when alphabet is entered
        if (!std::cin.fail()) // if no error is detected in cin
        {
            if (result >= range.min && result <= range.max)
                break;

            std::cout << std::fixed << std::setprecision(2);
            std::cout << "> Input a number between " << range.min << " and " << range.max << ": ";
            std::cout.unsetf(std::ios::fixed); // revert std::fixed
            continue;
        }

        // error in user input
        std::cin.clear();                                                   // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input
        // ^ says discard all input including newline character

        std::cout << "> Please input a valid input: ";
    }

    return result;
}
