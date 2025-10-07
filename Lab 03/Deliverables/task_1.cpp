#include <iostream>

// utility; mainly used to improve readability
inline bool isDivisible(int input, int checkNum)
{
    return input % checkNum == 0;
}

int main()
{
    int input_num;

    std::cout << "Enter a Number to check divisibility of: ";
    std::cin >> input_num;
    std::cout << std::endl;

    if (isDivisible(input_num, 2))
    {
        std::cout << "You entered an EVEN number (" << input_num << ")\n";
        if (isDivisible(input_num, 4))
        {
            std::cout << input_num << " is divisible by 4\n";
        }
        if (isDivisible(input_num, 6))
        {
            std::cout << input_num << " is divisible by 6\n";
        }
    }
    else
    {
        std::cout << "You entered an ODD number (" << input_num << ")\n";
        if (isDivisible(input_num, 3))
        {
            std::cout << input_num << " is divisible by 3\n";
        }
        if (isDivisible(input_num, 5))
        {
            std::cout << input_num << " is divisible by 5\n";
        }
    }


    // ignore is used to clear previous inputs from user
    std::cin.ignore();
    std::cin.get();
    return 0;
}