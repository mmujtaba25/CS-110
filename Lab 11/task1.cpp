#include <iostream>

int sumArray(const int arr[], int size)
{
    // return if first element reached
    if (size == 0)
        return 0;

    // add array from last element to first
    return arr[size - 1] + sumArray(arr, size - 1);
}

int countOccurrences(const int arr[], int size, int element)
{
    // return if first element reached
    if (size == 0)
        return 0;

    int occurrence = (arr[size - 1] == element) ? 1 : 0;
    return occurrence + countOccurrences(arr, size - 1, element);
}

int main()
{
    constexpr size_t SIZE = 10;
    int arr[SIZE]{0};

    std::cout << "Enter " << SIZE << " integers:\n";

    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cin >> arr[i];
    }

    int element;
    std::cout << "Enter an integer to count its occurrences: ";
    std::cin >> element;

    std::cout << "Sum of array elements: " << sumArray(arr, SIZE) << "\n";
    std::cout << "Occurrences of " << element << ": " << countOccurrences(arr, SIZE, element) << "\n";

    return 0;
}
