#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int numDigits(int number);

// templates prototypes works, because definations are given later

template <size_t M, size_t N>
void printMatrix(int matrix[M][N], int spacing = 0);

int main()
{
    constexpr int M = 6;
    constexpr int N = 6;

    int mat1[M][N];
    int mat1_b[M][N];

    unsigned int seed;
    std::cout << "Enter Seed (-1 for random): ";
    std::cin >> seed;

    seed = (seed == -1u ? time(0) : seed);

    int thresholdValue = 0;
    int sum_elements = 0;

    // init mat1
    srand(seed);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat1[i][j] = rand() % 255;
            sum_elements += mat1[i][j];
        }
    }

    // clamp to 255
    thresholdValue = sum_elements / M * N;
    thresholdValue %= 255;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat1[i][j] > thresholdValue)
                mat1_b[i][j] = 1;
            else
                mat1_b[i][j] = 0;
        }
    }

    std::cout << "\n\nMatrix 1\n";
    printMatrix<M, N>(mat1);

    std::cout << "\n\nBinarized Matrix 1\n";
    printMatrix<M, N>(mat1_b);

    return 0;
}

int numDigits(int number)
{
    int digits = 0;
    bool negative = number < 0;
    number = std::abs(number); // ignore -ive sign

    // number between 0 and 10
    if (number > 0 && number < 10)
    {
        digits = 1;
        goto return_digit;
    }

    // this is false when number is less then 0
    while (number > 0)
    {
        number /= 10;
        digits++;
    }

return_digit:
    return digits + (negative ? 1 : 0); // add one is digit is negative
}

template <size_t M, size_t N>
void printMatrix(int matrix[M][N], int spacing)
{
    constexpr int padding = 2;
    int max_spacing = 1;
    // calculate spacing
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            max_spacing = std::max(numDigits(matrix[i][j]) + padding, max_spacing);
        }
    }

    // use user given option if possible
    max_spacing = std::max(max_spacing, spacing);

    for (size_t i = 0; i < M; i++)
    {
        std::cout << "|";
        for (size_t j = 0; j < N; j++)
        {
            std::cout << std::right << std::setw(max_spacing) << matrix[i][j];
        }
        std::cout << " |\n";
    }
}
