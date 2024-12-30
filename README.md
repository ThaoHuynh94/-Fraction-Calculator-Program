# Fraction Arithmetic Operations Program

This is a simple console-based C++ program that performs arithmetic operations on fractions. The program allows users to input two fractions and select an operation (addition, subtraction, multiplication, or division) to be performed on them. It ensures proper input validation and handles common exceptions like division by zero.

## Features

- **Menu-based Interface**: The program starts by displaying a menu with two options:
  1. Input your own fractions and perform operations.
  2. Exit the program.
  
- **Fraction Input**: Users can input the numerator and denominator for two fractions. The program ensures that the denominator is not zero.
  
- **Arithmetic Operations**: The program supports four operations on fractions:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)

- **Error Handling**: The program includes robust exception handling to manage:
  - Invalid inputs (e.g., non-numeric values or out-of-range choices).
  - Division by zero errors.
  - Invalid fraction input (e.g., zero denominator).
  
- **Result Display**: After performing an operation, the program displays the result of the operation in fraction form.

## Requirements

- C++ compiler (e.g., GCC, Clang)
- C++11 or later

## Files

- **Fraction.h**: Header file containing the `Fraction` class and its member functions.
- **main.cpp**: The main program logic that handles user input, menu display, and operations.
- **Fraction.cpp**: Implementation of the `Fraction` class and its arithmetic operators.
