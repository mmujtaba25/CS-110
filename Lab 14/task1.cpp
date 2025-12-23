#include <iostream>

struct Point
{
    double x;
    double y;
};

int main()
{
    Point p1 = {3.0, 4.0};
    Point p2 = {6.0, 8.0};

    double distance = std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));

    std::cout << "Point 1: (" << p1.x << ", " << p1.y << ")\n";
    std::cout << "Point 2: (" << p2.x << ", " << p2.y << ")\n";
    std::cout << "Distance between points: " << distance << std::endl;

    return 0;
}