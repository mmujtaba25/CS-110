#include <iostream>

int *getSmallest(int *arr, int size);

int main()
{
    constexpr int SIZE = 10;
    int arr[SIZE] = {-5, 3, 0, -2, 8, 7, -1, 4, 6, 2};

    int *minPtr = getSmallest(arr, SIZE);

    std::cout << "Smallest value: " << *minPtr << std::endl;
    std::cout << "Address of smallest value: " << minPtr << std::endl;
    return 0;
}

int *getSmallest(int *arr, int size)
{
    int *minPtr = &arr[0];
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < *minPtr)
        {
            minPtr = &arr[i];
        }
    }
    return minPtr;
}
