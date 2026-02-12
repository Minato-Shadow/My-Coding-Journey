#include <iostream>
#include <ctime>     // For time()
#include <algorithm> // For transform()
#include <string>

int main()
{
    srand(time(NULL)); // Seed the random number generator

    int max_num, tries, random_num, user_guess;
    std::string difficulty, guess;

    std::cout << "########## Number Guessing Game ##########\n";

    while (true) // Main game loop (restarts if user wants to play again)
    {
        std::cout << "Enter Difficulty(Easy, Medium, Hard): ";
        std::getline(std::cin, difficulty); // Get full line input

        // Convert difficulty input to lowercase (so EASY, Easy, easy all work)
        std::transform(difficulty.begin(), difficulty.end(), difficulty.begin(), ::tolower);

        // Set game settings based on difficulty
        if (difficulty == "easy")
        {
            tries = 3;                         // Number of attempts
            max_num = 10;                      // Max number range
            random_num = rand() % max_num + 1; // Random number between 1 and max_num
        }
        else if (difficulty == "medium")
        {
            tries = 7;
            max_num = 50;
            random_num = rand() % max_num + 1;
        }
        else if (difficulty == "hard")
        {
            tries = 12;
            max_num = 100;
            random_num = rand() % max_num + 1;
        }
        else
        {
            // Default mode if user enters something invalid
            std::cout << "Something unexpected happened choosing easy mode by default\n";
            max_num = 10;
            tries = 3;
            random_num = rand() % max_num + 1;
        }

        // Guessing loop (runs until tries become 0 or player wins)
        while (tries > 0)
        {
            std::cout << "Guess a number between 1 and " << max_num << ": ";
            std::getline(std::cin, guess); // Take guess as string
            user_guess = std::stoi(guess); // Convert string to integer

            // Check if guess is out of range
            if (user_guess < 1 || user_guess > max_num)
            {
                std::cout << "Out of range!\n";
                continue; // Skip rest and ask again
            }
            else if (user_guess == random_num)
            {
                std::cout << "You won\n";
                break; // Exit guessing loop
            }
            else if (user_guess > random_num)
            {
                std::cout << "Guess lower\n";
                tries -= 1; // Decrease tries
                std::cout << tries << " tries remaining\n";
            }
            else if (user_guess < random_num)
            {
                std::cout << "Guess higher\n";
                tries -= 1;
                std::cout << tries << " tries remaining\n";
            }
            else
            {
                // This technically won’t run because stoi already converts to int
                std::cout << "Error! Please only enter number\n";
            }
        }

        // If player used all tries
        if (tries == 0)
        {
            std::cout << "You lost the number was " << random_num << '\n';
        }

        std::string play_again;
        std::cout << "Do you wanna play again? (y/n): ";
        std::getline(std::cin, play_again);

        // Convert answer to lowercase
        std::transform(play_again.begin(), play_again.end(), play_again.begin(), ::tolower);

        // Exit game if user does not enter yes/y
        if (play_again != "yes" && play_again != "y")
        {
            std::cout << "Thanks for playing\n";
            std::cout << "###########################################";
            break; // Exit main loop
        }
    }

    return 0; // Program ends successfully
}
