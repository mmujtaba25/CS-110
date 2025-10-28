#include <iostream>
#include <tuple>

enum class TempError
{
    None = 0,
    BelowAbsoluteZero = 1
};

TempError adjustTemp(double &temp, bool cToF);

int main()
{
    std::tuple<double, bool> testcases[10] = {
        {25.0, true},    // valid C
        {-300.0, true},  // invalid C
        {0.0, true},     // valid C
        {100.0, true},   // valid C
        {-500.0, false}, // invalid F
        {32.0, false},   // valid F
        {212.0, false},  // valid F
        {-460.0, false}, // invalid F
        {37.0, true},    // valid C
        {-40.0, true}    // same C and F
    };

    for (auto &[temp, isC] : testcases)
    {
        double tempBefore = temp;
        TempError error = adjustTemp(temp, isC);

        switch (error)
        {

        case TempError::None:
            std::cout << tempBefore << (isC ? " C" : " F") << " = " << temp << (!isC ? " C" : " F") << "\n";
            break;

        case TempError::BelowAbsoluteZero:
            std::cout << "ERROR: Invalid Tempurature (" << tempBefore << "" << (isC ? " C" : " F") << "): Tempurature is below Absolute Zero.\n";
            break;

        default:
            std::cout << "ERROR: Unknown Error Occured\n";
            break;
        }
    }

    std::cin.ignore();
    std::cin.get();
    return 0;
}

TempError adjustTemp(double &temp, bool cToF)
{
    TempError errorFlag = TempError::None;

    if (cToF)
    {
        // check if temp is above -273.15 C
        if (temp < -273.15)
        {
            errorFlag = TempError::BelowAbsoluteZero;
        }
        else
            temp = (temp * 9 / 5) + 32;
    }
    else
    {
        // check if temp is above -459.67 F
        if (temp < -459.67)
        {
            errorFlag = TempError::BelowAbsoluteZero;
        }
        else
            temp = (temp - 32) * 5 / 9;
    }

    return errorFlag;
}
