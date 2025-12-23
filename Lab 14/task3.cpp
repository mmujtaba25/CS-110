#include <iostream>

struct Student
{
    std::string name;
    int rollNumber;
    float marks;
};

int main()
{
    Student students[3];
    float totalMarks = 0;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> students[i].name;

        std::cout << "Enter roll number: ";
        std::cin >> students[i].rollNumber;

        std::cout << "Enter marks: ";
        std::cin >> students[i].marks;

        totalMarks += students[i].marks;
    }

    float averageMarks = totalMarks / 3;
    std::cout << "Class average marks: " << averageMarks << std::endl;

    return 0;
}
