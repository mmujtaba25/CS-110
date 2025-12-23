#include <iostream>

struct Book
{
    char title[30];
    char author[20];
    float price;
};

int main()
{
    Book *books = new Book[3];

    for (int i = 0; i < 3; i++)
    {
        char title[30];
        std::cout << "Enter Book title: ";
        std::cin >> title;

        char author[20];
        std::cout << "Enter Book Author: ";
        std::cin >> author;

        float price;
        std::cout << "Enter Book Price: ";
        std::cin >> price;

        Book *currentBook = (books + i);

        strcpy(currentBook->title, title);
        strcpy(currentBook->author, author);
        currentBook->price = price;
    }

    for (int i = 0; i < 3; i++)
    {
        Book *currentBook = (books + i);

        std::cout << "Book " << i << ": \n";
        std::cout << "Title: " << currentBook->title;
        std::cout << "Author: " << currentBook->author;
        std::cout << "Price: " << currentBook->price;

        std::cout << "\n\n";
    }

    delete[] books;
    return 0;
}