#include <iostream>
using namespace std;

int findMax(int *arr, int size)
{
    int maxVal = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > maxVal)
        {
            maxVal = *(arr + i);
        }
    }
    return maxVal;
}

int main()
{
    int numbers[5] = {9, 4, 11, 3, 2};

    cout << "Maximum value: " << findMax(numbers, 5);

    return 0;
}
