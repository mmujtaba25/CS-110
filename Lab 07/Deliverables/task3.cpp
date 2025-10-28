#include <iostream>
#include <iomanip>

enum class GravitationalForceError
{
    None = 0,
    ZeroRadius = -1,
    NegativeMass = -2,
};
inline double calculateForce(double first_mass, double second_mass, double radius, GravitationalForceError *error);

int main()
{
    std::tuple<double, double, double> testcases[10] = {
        {5.972e24, 7.348e22, 3.844e8},    // Earth and Moon
        {1.989e30, 5.972e24, 1.496e11},   // Sun and Earth
        {1.989e30, 7.348e22, 1.496e11 + 3.844e8}, // Sun and Moon
        {5.972e24, 0.0, 3.844e8},         // Earth and zero mass
        {-5.972e24, 7.348e22, 3.844e8},   // Negative mass > ERROR
        {5.972e24, 7.348e22, 0.0},        // Zero radius > ERROR
        {1.0e3, 1.0e3, 1.0},              // Small masses
        {1.0e10, 1.0e10, 1.0e5},          // Large masses
        {1.0, 1.0, 1.0},                  // Unit masses
        {2.0, 3.0, 4.0}                   // Random values
    };

    for (const auto &[first_mass, second_mass, radius] : testcases)
    {
        GravitationalForceError error = GravitationalForceError::None;

        double result = calculateForce(first_mass, second_mass, radius, &error);

        switch (error)
        {

        case GravitationalForceError::None:
            std::cout << "Calculated Force: " << result << " N\n";
            break;

        case GravitationalForceError::ZeroRadius:
            std::cout << "ERROR: Radius is zero.\n";
            break;

        case GravitationalForceError::NegativeMass:
            std::cout << "ERROR: One of the masses of negative.\n";
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

inline double calculateForce(double first_mass, double second_mass, double radius, GravitationalForceError *error = nullptr)
{
    if (first_mass < 0 || second_mass < 0)
    {
        *error = GravitationalForceError::NegativeMass;
        return -1;
    }

    if (radius == 0)
    {
        *error = GravitationalForceError::ZeroRadius;
        return -2;
    }

    constexpr double G_CONSTANT = 6.67430e-11;

    return (G_CONSTANT * first_mass * second_mass) / (radius * radius);
}
