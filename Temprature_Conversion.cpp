#include <iostream>

int main()
{
    double temp; // Stores the temprature value
    char unit;  // Stores the unit value

    // Display program titie
    std::cout << "===== Temprature Conversion ===== \n";

    // Show availabe conversions
    std::cout << "F = Fahrenheit\n";
    std::cout << "C = Celsuius\n";
    std::cout << "What unit would you like to convert to.\n";
    std::cout << "Enter unit: ";
    std::cin >> unit;

    // Convert unit to lower case
    unit = std::tolower(unit);

    switch (unit)
    {
        case 'f': // convert to Fahrenheit
            std::cout << "Enter the temprature in Celsius: ";
            std::cin >> temp;

            temp = (1.8 * temp) + 32;
            std::cout << "Temprature in Fahrenheit: " << temp << '\n';
            break;
        case 'c': // Convert to Celsius
            std::cout << "Enter the temprature in Fahrenheit: ";
            std::cin >> temp;

            temp = (temp - 32) / 1.8;
            std::cout << "Temprature in Celsius: " << temp << '\n';
            break;
        default: // Handles invalid input
            std::cout << "Something unexpected happend\n";
    }

    std::cout << "================================= \n";
    return 0; // end of program
}
