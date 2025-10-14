#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandom(int minInc, int maxInc);
bool askForGuess(int secret);

int main()
{
    srand(time(nullptr)); // for seeding rand() function

    // variables
    // int secret = getRandom(1, 100);
    int secret = 74;
    const size_t max_guesses = 5;
    bool has_guessed_correctly = false;

    std::cout << "Guess a magic number between 0 and 100.\n\n";

    for (size_t i = 0; i < max_guesses; i++)
    {
        has_guessed_correctly = askForGuess(secret);
        if (has_guessed_correctly)
            break;
    }

    if (!has_guessed_correctly)
    {
        std::cout << "You could not guess the number, it was " << secret << ".\n\n";
    }

    // ignoring previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}

// get random value for int (% operator only supports int) between given values inclusive
int getRandom(int minInc, int maxInc)
{
    // we later subtract bigger from smaller so swapping
    if (maxInc < minInc)
    {
        std::cerr << "WARNING> minInc is greater than maxInc. Swapping\n\n";
        std::swap(minInc, maxInc);
    }

    // first term: calculate random number from 0 to (max - min): min will be added later
    // second term: offset by min
    return (rand() % maxInc - minInc + 1) + minInc;
}

bool askForGuess(int secret)
{
    int guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;

    // if guessed correctly then return true
    if (guess == secret)
    {
        std::cout << "Yes, the number is " << secret << "\n\n";
        return true;
    }
    else if (guess >= secret)
    {
        std::cout << "You guess is " << (abs((float)(guess - secret)) > 25 ? "too " : "") << "high" << "\n\n";
    }
    else if (guess <= secret)
    {
        std::cout << "You guess is " << (abs((float)(guess - secret)) > 25 ? "too " : "") << "low" << "\n\n";
    }

    return false;
}