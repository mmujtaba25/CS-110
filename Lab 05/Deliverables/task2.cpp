#include <iostream>
#include <math.h>
#include <iomanip>

// utility for printing spaces
inline void print_spaces(int count, bool debug = false)
{
    // `count + 1` is used as std::setw sets the total width including the first charcter of next output field
    std::cout << std::setw(count + 1) << std::setfill(debug ? '.' : ' ');
}

void numberSquarePattern(int size);
void pyramidPattern(int lines_y);
void rightAlignedPyramidPattern(int lines_y, char toPrint);
void rightTrianglePattern(int size);

int main()
{
    std::cout << "\n----------------------------------\n\n";
    numberSquarePattern(6);
    std::cout << "\n----------------------------------\n\n";
    pyramidPattern(5);
    std::cout << "\n----------------------------------\n\n";
    rightAlignedPyramidPattern(5, '3');
    std::cout << "\n----------------------------------\n\n";
    rightTrianglePattern(6);
    std::cout << "\n----------------------------------\n\n";

    // ignore previous input
    std::cin.ignore();
    std::cin.get();
    return 0;
}

void numberSquarePattern(int size)
{
    // size is the size of square

    // at every place inside the region "size x size"
    // it only prints the character if it is at outer edge

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            // if first or last line, print all line
            if (i == 1 || i == size)
                std::cout << j;
            else
            {
                // if first or last item IN line, print "the number" otherwise print " "
                if (j == 1 || j == size)
                    std::cout << j;
                else
                    std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

void pyramidPattern(int lines_y)
{
    // lines_y is how many lines to print in vertical direction
    const int height = lines_y * 2; // height is two times "lines_y" as we skip even number lines
    // no cost as compiler will optimize this away

    // first calculate how many spaces are required for the character
    // then print the character just like a right facing triangle
    // CAN BE THOUGHT AS
    // first print right facing triangle then slant it
    // but processes on each line seperately

    int spaces_count;
    for (int i = 1; i <= height; i += 2) // `* 2` and `+= 2` as we only need to print even numbers
    {
        spaces_count = height - i;
        print_spaces(spaces_count);
        for (int j = 1; j <= height; j++)
        {
            if (j <= i)
                std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

void rightAlignedPyramidPattern(int lines_y, char toPrint)
{
    // if even number of lines are being printed we will print the middle line twice
    const int lines_y_half_ceiling = std::ceil(lines_y / 2.f); // pre calculate
    // will be optimzed away by compiler

    // same priciple as above
    // calculate spaces then print character

    int spaces_count;
    for (int i = 1; i <= lines_y; i++)
    {
        // print spaces
        spaces_count = std::abs(lines_y_half_ceiling - i) * 2;
        if (lines_y % 2 == 0 && i > lines_y_half_ceiling)
            spaces_count -= 2;
        print_spaces(spaces_count);
        // print characters
        for (int j = 1; j <= lines_y; j++)
        {
            // before middle point
            if (i <= lines_y_half_ceiling)
            {
                // print triangle facing left
                if (j <= i)
                    std::cout << toPrint << " ";
            }
            else
            {
                // print triangle facing right
                if (j >= i)
                    std::cout << toPrint << " ";
            }
        }
        std::cout << "\n";
    }
}

void rightTrianglePattern(int size)
{
    int spaces_count;
    for (int i = 1; i <= size; i++)
    {
        spaces_count = size - i;
        print_spaces(spaces_count * 2);
        for (int j = 1; j <= size; j++)
        {
            // print triangle facing left
            if (j <= i)
                std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
