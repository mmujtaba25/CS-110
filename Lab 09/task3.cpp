#include <iostream>
#include <random>

double getRandomNum(double minInclusive, double maxInclusive);
double min(double array[], size_t size);

int main()
{
    constexpr size_t TEST_ARRAY_SIZE = 10;
    double testArray[TEST_ARRAY_SIZE];

    for (size_t i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        testArray[i] = getRandomNum(-100, 100);
    }

    std::cout << "ARRAY: ";
    for (size_t i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        std::cout << testArray[i] << " ";
    }
    std::cout << "\n";

    std::cout << min(testArray, TEST_ARRAY_SIZE) << "\n";

    // std::cin.get();
    return 0;
}

double getRandomNum(double minInclusive, double maxInclusive)
{
    if (minInclusive > maxInclusive)
        std::swap(minInclusive, maxInclusive);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(minInclusive, maxInclusive);
    return distribution(gen);
}

double min(double array[], size_t size)
{
    double min = array[0];
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}
