#include <iostream> // For input and output

int main()
{
    // Infinite loop so calculator keeps running
    while (true)
    {
        // Declare variables
        double num1, num2, result;
        char op;

        // Display welcome message
        std::cout << "***** Welcome to Calculator *****" << '\n';

        // Take first number input
        std::cout << "Enter first number: ";
        std::cin >> num1;

        // Take second number input
        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Ask user for operation
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> op;

        // Perform calculation based on operator
        switch (op)
        {
        case '+': // Addition
            result = num1 + num2;
            std::cout << "The result is: " << result << '\n';
            break;

        case '-': // Subtraction
            result = num1 - num2;
            std::cout << "The result is: " << result << '\n';
            break;

        case '*': // Multiplication
            result = num1 * num2;
            std::cout << "The result is: " << result << '\n';
            break;

        case '/':          // Division
            if (num2 == 0) // Prevent division by zero
            {
                std::cout << "Can't divide by zero!" << '\n';
            }
            else
            {
                result = num1 / num2;
                std::cout << "The result is: " << result << '\n';
            }
            break;

        default: // If operator is invalid
            std::cout << "Invalid Op/number\n";
            break;
        }

        // Ask user if they want another calculation
        char answer;
        std::cout << "Do u wanna do another calculation?\n";
        std::cout << "Enter (y/n): ";
        std::cin >> answer;

        // Exit loop if answer is not y or Y
        if (answer != 'y' && answer != 'Y')
        {
            std::cout << "Exiting ...";
            break; // Breaks out of while loop
        }

        std::cout << '\n'; // Add spacing before next round
    }

    return 0; // Program ends successfully
}