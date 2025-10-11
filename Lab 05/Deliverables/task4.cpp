#include <iostream>

int main()
{
    float sum = 0;
    int count = 0;

    int tmp_input;
    std::cout << "Enter -1 to exit. \n\n";
    while (true)
    {
        std::cout << "Enter marks: ";
        std::cin >> tmp_input;

        // if input -1 then exit
        if (tmp_input == -1)
        {
            std::cout << "* Exiting... \n\n";
            break;
        }

        // check if between 0 and 10
        if (tmp_input <= 0 || tmp_input >= 100)
        {
            std::cout << "* Invalid number skipped \n";
            std::cout << "* Enter a number between 0 and 100. \n\n";
            continue; // take another numb from
        }

        sum += tmp_input;
        count++;
    }

    std::cout << "Average marks: " << sum / count << "\n";

    // ignore previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}
