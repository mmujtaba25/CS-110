#include <iostream>
#include <random>
#include <iomanip>

int getRandomNum(int minInclusive, int maxInclusive);
void sortArrayInPlace(int array[], const int size);
void printArray(int array[], const size_t size);

int main()
{
    constexpr size_t TEST_ARRAY_SIZE = 10;
    int testArray[TEST_ARRAY_SIZE];

    for (size_t i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        testArray[i] = getRandomNum(-100, 100);
    }

    std::cout << "BEFORE SORT: ";
    printArray(testArray, TEST_ARRAY_SIZE);

    sortArrayInPlace(testArray, TEST_ARRAY_SIZE);
    std::cout << "AFTER  SORT: ";
    printArray(testArray, TEST_ARRAY_SIZE);

    // std::cin.get();
    return 0;
}

void printArray(int array[], const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << std::right << std::setw(5) << array[i];
    }
    std::cout << "\n";
}

int getRandomNum(int minInclusive, int maxInclusive)
{
    if (minInclusive > maxInclusive)
        std::swap(minInclusive, maxInclusive);

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(minInclusive, maxInclusive);
    return distribution(gen);
}

void sortArrayInPlace(int array[], int size)
{
    // use bubble sort algorithm
    int i, j;
    for (j = 0; j < size; j++)
    {
        for (i = 0; i < (size - 1); i++)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
            }
        }
    }
}
