#include <iostream>

int uniquePaths(int m, int n)
{
    // base case: if we reach the last row or last column, there's only one path
    if (m == 1 || n == 1)
        return 1;

    // recursive case: sum of paths from the cell to the right and the cell below
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

int main()
{
    int m, n;
    std::cout << "Enter grid dimensions (m n): ";
    std::cin >> m >> n;

    int paths = uniquePaths(m, n);
    std::cout << "Number of unique paths: " << paths << "\n";

    return 0;
}