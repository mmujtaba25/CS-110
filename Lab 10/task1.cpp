#include <iostream>
#include <iomanip>

int numDigits(int number);

// templates prototypes works, because definations are given later

template <size_t M, size_t N>
void printMatrix(int matrix[M][N], int spacing = 0);

template <size_t M, size_t N, size_t P, size_t Q>
void multiplyMatrix(int mat1[M][N], int mat2[P][Q], int result[M][Q]);

template <size_t M, size_t N>
void readMatrix(int matrix[M][N]);

int main()
{
    constexpr int M = 3;
    constexpr int N = 3;
    constexpr int P = 3;
    constexpr int Q = 3;

    int mat1[M][N], mat2[P][Q];
    int prod[M][Q]; // for MxN * PxQ order is MxQ

    // init mat1
    std::cout << "Enter Matrix 1 (" << M << "x" << N << "):\n";
    readMatrix<M, N>(mat1);

    // init mat2
    std::cout << "Enter Matrix 2 (" << P << "x" << Q << "):\n";
    readMatrix<P, Q>(mat2);

    // init prod -> 0
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < Q; j++)
        {
            prod[i][j] = 0;
        }
    }

    multiplyMatrix<M, N, P, Q>(mat1, mat2, prod);

    // print mat1 matrix
    std::cout << "\n\nMatrix 1\n";
    printMatrix<M, N>(mat1);

    // print mat2 matrix
    std::cout << "\n\nMatrix 2\n";
    printMatrix<P, Q>(mat2);

    // print sum matrix
    std::cout << "\n\nProduct\n";
    printMatrix<M, Q>(prod);

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

template <size_t M, size_t N, size_t P, size_t Q>
void multiplyMatrix(int mat1[M][N], int mat2[P][Q], int result[M][Q])
{
    // loop over all elements in first row of mat1
    // loop over all elements in first column of mat2
    // multiply each element and sum[i][j] = sum

    if (N != P)
    {
        std::cout << "* Please use a valid index.";

        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = 0; j < Q; j++)
            {
                // set all to -1 in case of error
                result[i][j] = -1;
            }
        }
        return;
    }

    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < Q; j++)
        {
            int sum = 0;

            // sum[i][j] = summation(mat1[i][k] * mat2[k][j])
            // k goes from (0 -> N) where N in MxN * PxQ, note that P is same as N in this scenario
            for (size_t k = 0; k < N; k++)
            {
                sum += mat1[i][k] * mat2[k][j];
            }

            result[i][j] = sum;
        }
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
                    break; // valid integer

                // invalid input
                std::cout << "* Invalid input. Please enter an integer.\n";

                // silently discard invalid input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            matrix[i][j] = value;
        }
    }
}
