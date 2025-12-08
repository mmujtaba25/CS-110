#include <iostream>
#include <cstring>

constexpr size_t ISBN_STR_SIZE = 13;

int getChecksum(const char s[ISBN_STR_SIZE - 1]);

int main()
{
    // testing with example values
    char testValues[][ISBN_STR_SIZE] = {
        "978030640615", // 7
        "978014028657", // 1
        "978160234061"  // 9
        // values tested from https://freeisbn.com/check-digit/
    };

    for (auto &arr : testValues)
    {
        int checksum = getChecksum(arr);

        std::cout << "The ISBN-13 number is: ";
        for (size_t i = 0; i < ISBN_STR_SIZE - 1; ++i)
            std::cout << arr[i];

        std::cout << checksum << "\n";
    }

    char isbn[ISBN_STR_SIZE]; // 12 + null digit
    std::cout << "Enter first 12 digits of ISBN: ";
    std::cin >> isbn;

    int checksum = getChecksum(isbn);
    std::cout << "The ISBN-13 number is: " << isbn << checksum << "\n";

    return 0;
}

int getChecksum(const char s[ISBN_STR_SIZE - 1])
{
    // works because of ascii values ordering
    // '0' translates to ascii value of 0
    int d1 = s[0] - '0';
    int d2 = s[1] - '0';
    int d3 = s[2] - '0';
    int d4 = s[3] - '0';
    int d5 = s[4] - '0';
    int d6 = s[5] - '0';
    int d7 = s[6] - '0';
    int d8 = s[7] - '0';
    int d9 = s[8] - '0';
    int d10 = s[9] - '0';
    int d11 = s[10] - '0';
    int d12 = s[11] - '0';

    // applying formula
    int checksum = 10 - ((d1 + 3 * d2 + d3 + 3 * d4 + d5 + 3 * d6 + d7 + 3 * d8 + d9 + 3 * d10 + d11 + 3 * d12) % 10);

    // return 0 if 10
    return (checksum == 10) ? 0 : checksum;
}
