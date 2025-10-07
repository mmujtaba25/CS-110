#include <iostream>
#include <iomanip> // manipulators for printRow

float getPrice(int product_id);
void printRow(const char *colA, const char *colB);
void printProductTable();

int main()
{
    int product_id, quantity;
    float total = 0.f;
    float discount = 0.f;

    printProductTable();
    // loop to run until valid value for product id is entered by user
    while (true)
    {
        std::cout << "Enter Product ID: ";
        std::cin >> product_id;
        std::cout << "\n";

        if (getPrice(product_id) == -1)
        {
            std::cout << "Please input a valid value from the table";
            printProductTable();
            continue;
        }

        // break out of loop when value is validated
        break;
    }

    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    std::cout << "\n";

    total = getPrice(product_id) * quantity;

    // apply 10% discount is user buys more than 5 items
    if (quantity > 5)
        discount = total * (10.f / 100);

    std::cout << "Final amount owed: $" << total - discount << std::endl;

    // print discount info
    if (discount > 0)
    {
        std::cout << std::endl;
        std::cout << "Discount Applied: $" << discount << std::endl;
        std::cout << "Without Discount: $" << total << std::endl;
    }

    // ignore is used to clear previous inputs from user
    std::cin.ignore();
    std::cin.get();
    return 0;
}

float getPrice(int product_id)
{
    switch (product_id)
    {
    // no break is needed as return does the job
    case 1:
        return 2.98f;
    case 2:
        return 4.5f;
    case 3:
        return 9.98f;
    case 4:
        return 4.49f;
    case 5:
        return 6.87f;

    default:
        return -1.f;
    }
}

void printRow(const char *colA, const char *colB)
{
    std::cout << " " << std::left << std::setw(4) << colA << " | " << colB << "\n";
}

// print a formatted table that shows all product; could use unordered or ordered map
void printProductTable()
{
    const char *LINES = "--------------";
    std::cout << "\n\n"
              << LINES << "\n";
    printRow("ID", "Price");
    std::cout << LINES << "\n";
    printRow("1", "$2.98");
    printRow("2", "$4.50");
    printRow("3", "$9.98");
    printRow("4", "$4.49");
    printRow("5", "$6.87");
    std::cout << LINES << "\n\n";
}