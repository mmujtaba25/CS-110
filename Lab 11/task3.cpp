#include <iostream>
#include <string>

bool checkPalindrome(const std::string &str, int left, int right)
{
    // check if first and last is same
    // repeat for next pair

    // passed middle
    if (left >= right)
        return true;

    // at any point if not same, return false
    if (str[left] != str[right])
        return false;

    // move towards the middle
    return checkPalindrome(str, left + 1, right - 1);
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (checkPalindrome(input, 0, input.length() - 1))
        std::cout << "The string is a palindrome.\n";
    else
        std::cout << "The string is not a palindrome.\n";

    return 0;
}