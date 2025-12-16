#include <iostream>

int main()
{
    float var;
    float *ptr_var = &var;

    *ptr_var = 3.14;

    std::cout << "Value using variable: " << var << "\n";
    std::cout << "Value using pointer:  " << *ptr_var << "\n";
    return 0;
}