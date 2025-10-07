#include <iostream>
#include <random>

// get random value of type T (can be any type) between given values inclusive
template <typename T>
T getRandom(T minInc, T maxInc)
{
    std::random_device rd;  // get a random device
    std::mt19937 gen(rd()); // using a random engine
    // "uniform_int_distribution" used to remove random bias
    std::uniform_int_distribution<> distrib(minInc, maxInc);
    // return the number
    return distrib(gen);
}

int main()
{
    // variables
    size_t guess_counter = 0; // size_t is commonly used for counters in cpp
    unsigned int secret = getRandom<int>(1, 10); // not negative; <int> is not required but used to emphasize that template function is used
    unsigned int guess; // not negative

    // MAIN LOOP
    std::cout << "I have chosen a number between 1 and 10. Try to guess it.\n\n";
    do // do while is used to intialize the guess of user
    {
        std::cout << "Your guess: ";
        std::cin >> guess;
        // newline by using pressing enter

        // increase stored guess counter
        guess_counter++;

        // if guessed correctly then print and exit
        if (secret == guess)
        {
            std::cout << "\n\nThat's right! You guessed it. \n";
            std::cout << "It only took you " << guess_counter << " tries.\n";
            break;
        }

        // if not executed -> guess is wrong
        std::cout << "\nThat is incorrect! Guess Again.\n";
    } while (secret != guess);

    // ignoring previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}
