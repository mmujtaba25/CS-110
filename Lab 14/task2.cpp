#include <iostream>

struct Clock
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    Clock time;

    std::cout << "Enter -1 to exit at any time." << std::endl;
    std::string input = "0";
    while (std::stoi(input) != -1)
    {
        std::cout << "Enter hours: ";
        std::cin >> input;
        if (std::stoi(input) == -1)
            break;
        time.hours = std::stoi(input);
        if (time.hours < 0 || time.hours > 23)
        {
            std::cout << "Invalid hours. Please enter a value between 0 and 23." << std::endl;
            continue;
        }

        std::cout << "Enter minutes: ";
        std::cin >> input;
        if (std::stoi(input) == -1)
            break;
        time.minutes = std::stoi(input);
        if (time.minutes < 0 || time.minutes > 59)
        {
            std::cout << "Invalid minutes. Please enter a value between 0 and 59." << std::endl;
            continue;
        }

        std::cout << "Enter seconds: ";
        std::cin >> input;
        if (std::stoi(input) == -1)
            break;
        time.seconds = std::stoi(input);
        if (time.seconds < 0 || time.seconds > 59)
        {
            std::cout << "Invalid seconds. Please enter a value between 0 and 59." << std::endl;
            continue;
        }

        std::cout << "Time: " << time.hours << ":" << time.minutes << ":" << time.seconds << std::endl;
    }

    std::cout << "Exiting program." << std::endl;

    return 0;
}