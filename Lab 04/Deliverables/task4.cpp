#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

int main()
{
    int num_items = 0;
    std::string lowest_name = "";
    // float is not a simple type like int so we cannot just flip all bits to one, that is NaN
    float lowest_price = std::numeric_limits<float>::max(); // storing max value that can be stored in float

    std::cout << "Number of items to Enter: ";
    std::cin >> num_items;
    std::cout << "\n";
    std::cout << std::setw(32) << std::setfill('-') << "\n";
    std::cout << "\n";

    for (int i = 1; i <= num_items; i++)
    {
        std::string name = "";
        float price = 0;

        std::cout << i << ". Enter the Item Name: ";
        std::cin.ignore(); // ignoring previous input
        std::getline(std::cin, name);
        // getline reads until newline from the given stream (std::cin in this case) and stores it in the given strings

        std::cout << i << ". Enter the Item Price: ";
        std::cin >> price;
        // newline by user pressing enter

        // compare to already stored lowest value, if this is lower then update lowest
        // no need to compare names
        if (price <= lowest_price)
        {
            lowest_name = name;
            lowest_price = price;
        }

        // spacer for next item
        std::cout << std::endl;
    }
    std::cout << "\n";
    std::cout << std::setw(32) << std::setfill('-') << "\n";
    std::cout << "\n";
    std::cout << "Name of lowest Item: " << lowest_name << "\n";
    std::cout << "Price of lowest Item: " << lowest_price << "\n";

    // ignoring previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}
