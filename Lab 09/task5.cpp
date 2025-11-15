#include <iostream>
#include <random>
#include <iomanip>

int getRandomNum(int minInclusive, int maxInclusive);
void sortArrayInPlace(int array[], const int size);
void printArray(int array[], const size_t size);

int getElementIndex(int array[], const size_t size, int element);

int main()
{
    constexpr size_t TEST_ARRAY_SIZE = 100;
    int testArray[TEST_ARRAY_SIZE];

    for (size_t i = 0; i < TEST_ARRAY_SIZE; i++)
    {
        testArray[i] = getRandomNum(-999, 999);
    }

    sortArrayInPlace(testArray, TEST_ARRAY_SIZE);

    std::cout << "SORTED ARRAY:\n";
    printArray(testArray, TEST_ARRAY_SIZE);
    std::cout << "\n";

    int toFound;
    std::cout << "Enter element to find from array: ";
    std::cin >> toFound;

    std::cout << "[" << toFound << "] at index " << getElementIndex(testArray, TEST_ARRAY_SIZE, toFound) << "\n";

    // std::cin.get();
    return 0;
}

void printArray(int array[], const size_t size)
{
    constexpr size_t COLUMNS = 5;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "[" << std::setw(4) << std::right << array[i] << " @ " << std::setw(4) << std::left << i << "] ";
        if (i % COLUMNS == COLUMNS - 1)
        {
            std::cout << "\n";
        }
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

int getElementIndex(int array[], const size_t size, int element)
{
    int min = 0;
    int max = static_cast<int>(size) - 1;
    int firstIndex = -1;

    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (array[mid] > element)
            max = mid - 1;
        else if (array[mid] < element)
            min = mid + 1;
        else
        {
            firstIndex = mid;
            max = mid - 1; // force left search
        }
    }

    // if not found return -1
    return firstIndex;
}
