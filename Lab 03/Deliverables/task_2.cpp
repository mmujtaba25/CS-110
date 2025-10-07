#include <iostream>
#include <string>

int main()
{
    float marks;
    char grade = ' ';

    std::cout << "Enter marks: ";
    std::cin >> marks;
    std::cout << "\n";

    if (marks >= 70)
        grade = 'A';
    else if (marks >= 60 && marks < 70)
        // even though condition `marks < 70` is not required
        // it is included to imporve readability
        grade = '+'; // assigning unique character
    else if (marks >= 50 && marks < 60)
        grade = 'B';
    else if (marks >= 40 && marks < 50)
        grade = 'C';
    else if (marks < 40)
        grade = 'F';

    // when printing convert '+' to "B+" (char -> std::string)
    // converting because string allows storing multiple characters
    std::string grade_printable;
    if (grade == '+')
        grade_printable = "B+";
    else
        grade_printable = grade;
    std::cout << marks << " marks equate to grade " << grade_printable << std::endl;

    switch (grade)
    {
    case 'A':
        std::cout << "Outstanding!" << std::endl;
        break;
    case '+':
        std::cout << "Excellent!" << std::endl;
        break;
    case 'B':
        std::cout << "Very Good!" << std::endl;
        break;
    case 'C':
        std::cout << "Good!" << std::endl;
        break;
    case 'F':
        std::cout << "Fail!" << std::endl;
        break;

    default:
        std::cout << "THIS WILL NEVER PRINT" << std::endl;
        break;
    }

    // ignore is used to clear previous inputs from user
    std::cin.ignore();
    std::cin.get();
    return 0;
}