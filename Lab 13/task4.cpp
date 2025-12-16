#include <iostream>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(arr + i) << " ";
        *(arr + i) += 5;
    }

    std::cout << "\n += 5 for all\n";

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(arr + i) << " ";
    }

    std::cout << "\n";
    return 0;
}