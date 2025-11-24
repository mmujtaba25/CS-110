#include <iostream>
#include <iomanip>
#include <limits>

int numDigits(int number);

template <size_t M, size_t N>
void printMatrix(int matrix[M][N], int spacing = 0);

template <size_t M, size_t N>
void readMatrix(int matrix[M][N]);

int main()
{
    constexpr int N = 5;
    int adjacency[N][N];

    std::cout << "Enter adjacency matrix (" << N << "x" << N << "):\n";
    readMatrix<N, N>(adjacency);

    int inDegrees[N] = {0};
    int outDegrees[N] = {0};

    // compute degrees
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            outDegrees[i] += adjacency[i][j]; // sum of row = out-degree
            inDegrees[j] += adjacency[i][j];  // sum of column = in-degree
        }
    }

    std::cout << "\nAdjacency Matrix:\n";
    printMatrix<N, N>(adjacency);

    for (size_t i = 0; i < N; i++)
    {
        std::cout << "Node #" << i << ": out-degree = " << outDegrees[i]
                  << ", in-degree = " << inDegrees[i] << "\n";
    }

    return 0;
}

int numDigits(int number)
{
    int digits = 0;
    bool negative = number < 0;
    number = std::abs(number);

    if (number > 0 && number < 10)
    {
        digits = 1;
        goto return_digit;
    }

    while (number > 0)
    {
        number /= 10;
        digits++;
    }

return_digit:
    return digits + (negative ? 1 : 0);
}

template <size_t M, size_t N>
void printMatrix(int matrix[M][N], int spacing)
{
    constexpr int padding = 2;
    int max_spacing = 1;

    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            max_spacing = std::max(numDigits(matrix[i][j]) + padding, max_spacing);
        }
    }

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

template <size_t M, size_t N>
void readMatrix(int matrix[M][N])
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            int value;
            while (true)
            {
                std::cout << "Enter value for [" << i << "][" << j << "]: ";
                if (std::cin >> value)
                    break;

                std::cout << "* Invalid input. Please enter an integer.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            matrix[i][j] = value;
        }
    }
}
