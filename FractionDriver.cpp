#include <iostream>
#include "Fraction.h"
#include <stdexcept>

// Displays the menu and handles user choices
/**
 * @brief Displays a menu for the user to select an operation.
 */
void menu();

// Handles user input for fractions and performs arithmetic operations
/**
 * @brief Prompts user to input two fractions and select an operation to perform on them.
 *
 * This function allows the user to input two fractions and perform one of the four arithmetic operations on them.
 */
void userInteraction();

int main() {
    try {
        menu(); // Call the menu function to start the program
    } catch (const std::exception& e) {
        // Catch any exceptions and display an error message
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

void menu() {
    int choice;
    bool exitMenu = false;

    // Loop to display the menu until the user exits
    while (!exitMenu) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter your own fractions and perform operations\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        // Validate user input for choice
        while (std::cin.fail() || choice < 1 || choice > 2) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 2: ";
            std::cin >> choice;
        }

        try {
            switch (choice) {
                case 1:
                    userInteraction(); // Call user interaction to input fractions and perform operations
                    break;
                case 2:
                    exitMenu = true; // Set flag to exit the menu loop
                    std::cout << "Exiting the program.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const std::exception& e) {
            // Catch and display any exceptions during menu processing
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void userInteraction() {
    int numerator, denominator;
    char operation;

    try {
        // Get user input for the first fraction
        std::cout << "Enter the numerator and denominator for the first fraction: ";
        std::cin >> numerator >> denominator;
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        Fraction frac1(numerator, denominator);

        // Get user input for the second fraction
        std::cout << "Enter the numerator and denominator for the second fraction: ";
        std::cin >> numerator >> denominator;
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        Fraction frac2(numerator, denominator);

        // Display the fractions
        std::cout << "First Fraction: " << frac1 << std::endl;
        std::cout << "Second Fraction: " << frac2 << std::endl;

        // Ask the user for an operation to perform on the fractions
        std::cout << "Enter an operation (+, -, *, /) to perform on these fractions: ";
        std::cin >> operation;

        Fraction result; // Variable to store the result of the operation

        // Switch to handle the different operations
        switch (operation) {
            case '+':
                result = frac1 + frac2; // Perform addition
                std::cout << "Result of addition: " << result << std::endl;
                break;
            case '-':
                result = frac1 - frac2; // Perform subtraction
                std::cout << "Result of subtraction: " << result << std::endl;
                break;
            case '*':
                result = frac1 * frac2; // Perform multiplication
                std::cout << "Result of multiplication: " << result << std::endl;
                break;
            case '/':
                // Check for division by zero in the second fraction
                if (frac2.getNumerator() == 0) {
                    throw std::logic_error("Error: Cannot divide by zero fraction.");
                }
                result = frac1 / frac2; // Perform division
                std::cout << "Result of division: " << result << std::endl;
                break;
            default:
                std::cout << "Invalid operation." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        // Catch invalid input (e.g., zero denominator) and display error message
        std::cout << "Invalid input: " << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        // Catch division by zero error and display message
        std::cout << "Logic error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch any other exceptions
        std::cout << "Error: " << e.what() << std::endl;
    }
}
