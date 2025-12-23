#include <iostream>

struct Book
{
    char title[50];
    char author[30];
    int year;
    float price;
};

bool isValidBook(const Book &b)
{
    // check year
    if (b.year < 1900 || b.year > 2023)
        return false;
    // check price
    if (b.price <= 0)
        return false;
    // check title
    if (b.title[0] == '\0') // for char array, it ends when it reaches null character
        return false;
    return true;
}

int main()
{
    Book book;

    std::cout << "Enter book title: ";
    std::cin.getline(book.title, 50);

    std::cout << "Enter author name: ";
    std::cin.getline(book.author, 30);

    std::cout << "Enter publication year: ";
    std::cin >> book.year;

    std::cout << "Enter price: ";
    std::cin >> book.price;

    if (isValidBook(book))
    {
        std::cout << "Valid Book" << std::endl;
        std::cout << "Title: " << book.title << std::endl;
        std::cout << "Author: " << book.author << std::endl;
        std::cout << "Year: " << book.year << std::endl;
        std::cout << "Price: " << book.price << std::endl;
    }
    else
    {
        std::cout << "Invalid Book" << std::endl;
    }

    return 0;
}
