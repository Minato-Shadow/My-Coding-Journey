#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <thread>
#include <chrono>

int main()
{
    // Initial welcome screen
    std::cout << "~~~~~~~~~~ Banking Simulator ~~~~~~~~~~\n";
    std::cout << "Enter your username: ";

    std::string username;
    std::cin >> username; // Takes single-word username

    std::cout << "Enter pincode: ";
    int pincode;
    std::cin >> pincode; // Simple authentication setup

    // Randomly generate a starting balance for simulation
    std::random_device rd;                                        // Seed source
    std::mt19937 gen(rd());                                       // Random number engine
    std::uniform_real_distribution<double> dist(1.0, 999999999999.0); // Balance range

    double balance = dist(gen); // Assign random starting balance

    // Format output to always show 2 decimal places (money format)
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nWelcome, " << username << "!\n";
    std::cout << "Your starting balance is ₹" << balance << "\n\n";

    // Main banking loop
    while (true)
    {
        std::cout << "\n1. Deposit Money\n";
        std::cout << "2. Withdraw Money\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter Command (1, 2, 3): ";

        char command;
        std::cin >> command; // Menu selection

        switch (command)
        {
        case '1':
        {
            std::cout << "Enter amount to deposit: ";
            double amount_to_deposit;
            std::cin >> amount_to_deposit;

            // Prevent invalid or negative deposits
            if (amount_to_deposit <= 0)
            {
                std::cout << "Invalid amount!\n";
                break;
            }

            // Simulate transaction delay
            std::cout << "Processing transaction...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));

            balance += amount_to_deposit;

            std::cout << "Transaction successful!\n";
            std::cout << "Balance: ₹" << balance << "\n";
            break;
        }

        case '2':
        {
            std::cout << "Enter amount to withdraw: ";
            double amount_to_withdraw;
            std::cin >> amount_to_withdraw;

            // Validate withdrawal amount
            if (amount_to_withdraw <= 0)
            {
                std::cout << "Invalid amount!\n";
                break;
            }

            // Prevent overdrawing
            if (amount_to_withdraw > balance)
            {
                std::cout << "You can't withdraw more than your balance!\n";
                break;
            }

            // Simulate processing delay
            std::cout << "Processing transaction...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));

            balance -= amount_to_withdraw;

            std::cout << "Transaction successful!\n";
            std::cout << "Balance: ₹" << balance << "\n";
            break;
        }

        case '3':
        {
            std::cout << "Enter your pincode to exit: ";
            int check_pincode;
            std::cin >> check_pincode;

            // Simple authentication check before exiting
            if (pincode == check_pincode)
            {
                std::cout << "Thanks for using our bank!\n";
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";        
                return 0; // Proper program termination
            }
            else
            {
                // Fun dramatic exit sequence
                std::cout << "Wrong Pincode!!\n";
                std::cout << "Initialising Self Destruct\n";
                std::cout << "3\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "2\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "1\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Boom 💥\n";
                return 0;
            }
        }

        default:
            // Handles unexpected input
            std::cout << "Invalid command! Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
