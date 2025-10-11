#include <iostream>

int main()
{
    int min_x = 0;
    int max_x = 5;
    int min_y = 0;
    int max_y = 5;

    for (int i = min_x; i <= max_x; i++)
    {
        for (int j = min_y; j <= max_y; j++)
        {
            std::cout << "(" << i << ", " << j << ") ";
        }
        std::cout << "\n";
    }

    std::cin.ignore();
    std::cin.get();
    return 0;
}
