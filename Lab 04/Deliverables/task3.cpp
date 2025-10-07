#include <iostream>

int main()
{
    int input_n = 0;
    int factorial = 1; // intializing to 1 instead of 0

    std::cout << "Input a number to find factorial of: ";
    std::cin >> input_n;
    // newline by user pressing enter

    // if user user inputs 0 program doesn't run and returns stored value of `factorial` i.e 1
    // start from 1 and multulpy all numbers till `input_n`; store result in `factorial`
    for (int i = 1; i <= input_n; i++)
    {
        factorial *= i;
    }

    std::cout << "Factorial of " << input_n << " is " << factorial << "\n";

    // ignoring previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}
