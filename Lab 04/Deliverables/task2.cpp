#include <iostream>

int main()
{
    int input_n = 0;
    // using double for more accuracy
    double result_numerator = 0.f;
    double result_denominator = 0.f;

    std::cout << "Enter the amount of inputs: ";
    std::cin >> input_n;
    // newline by user pressing enter

    result_numerator = input_n;

    // take `input_n` values from user
    int counter = 1;
    do
    {
        float x_i;
        std::cout << "Enter x" << counter << ": ";
        std::cin >> x_i;
        // newline by user pressing enter

        result_denominator += 1.f / x_i;
        counter++;
    } while (counter <= input_n);

    std::cout << "Harmonic mean if your input numbers is " << result_numerator / result_denominator << "\n";

    // ignoring previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}
