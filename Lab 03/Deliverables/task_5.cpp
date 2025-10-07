#include <iostream>

void printCase(char a)
{
    // WORKING PRINCIPLE
    // char is basically be thought of as a unsigned 8 bit integer
    // the computer stores a map from each possible number 0-255 to a specific symbol
    // in this map, small, capital, digits etc are sequential, comes after one another
    // by using only (char) >= (char) both are implicitely converted to int and compared
    // as said since digits are mapped sequentially the number representation of a small alphabet is between the number representation of `a` and `z`
    // same holds for capital letters and digits
    if (a >= (int)'a' && a <= (int)'z')
        std::cout << "You entered SMALL letter \'" << a << "\'";
    else if (a >= 'A' && a <= 'Z')
        std::cout << "You entered CAPITAL letter \'" << a << "\'";
    else if (a >= '0' && a <= '9')
        std::cout << "You entered DIGIT \'" << a << "\'";
    else
        std::cout << "You entered SPECIAL character \'" << a << "\'";
    // (a >= 'a' && a <= 'z') can also be written as
    // (a >= (int)'a' && a <= (int)'z')
    // above is not used as this clutters the code
    std::cout << "\n";
}

int main()
{
    char inputChar;

    std::cout << "Enter a character: ";
    std::cin >> inputChar;
    std::cout << "\n";

    printCase(inputChar);

    // ignore is used to clear previous inputs from user
    std::cin.ignore();
    std::cin.get();
    return 0;
}
