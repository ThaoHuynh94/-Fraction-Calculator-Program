#ifndef FRACTION_H
#define FRACTION_H

#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>

/**
 * @class Fraction
 * @brief Represents a mathematical fraction with a numerator and a denominator.
 * Provides basic operations for fraction manipulation, including arithmetic operations (addition, subtraction, multiplication, division),
 * relational operators, and conversion to a string representation.
 */
class Fraction {
private:
    long numerator;      ///< Numerator of the fraction
    long denominator;    ///< Denominator of the fraction

    /**
     * @brief Reduces the fraction to its simplest form.
     * Simplifies the fraction by dividing both the numerator
     * and the denominator by their greatest common divisor (GCD).
     */
    void reduce();

    /**
     * @brief Calculates the greatest common divisor (GCD) of two numbers.
     * Uses the Euclidean algorithm.
     * @param a First number
     * @param b Second number
     * @return The GCD of the two numbers.
     */
    long gcd(long a, long b);

public:

    Fraction():numerator(1), denominator(1){}


    /**
     * @brief Parameterized constructor with exception handling.
     * Throws an exception if the denominator is zero.
     * @param numerator Numerator of the fraction
     * @param denominator Denominator of the fraction
     * @throws std::logic_error if the denominator is zero.
     */
    Fraction(long numerator, long denominator);

    // Setters
    /**
     * @brief Sets the numerator of the fraction.
     * @param numerator The new numerator value.
     */
    void setNumerator(long numerator);

    /**
     * @brief Sets the denominator of the fraction.
     * Throws an exception if the denominator is zero.
     * @param denominator The new denominator value.
     * @throws std::logic_error if the denominator is zero.
     */
    void setDenominator(long denominator);

    // Getters
    /**
     * @brief Gets the numerator of the fraction.
     * @return The numerator of the fraction.
     */
    long getNumerator() const;

    /**
     * @brief Gets the denominator of the fraction.
     * @return The denominator of the fraction.
     */
    long getDenominator() const;

    // Overloaded Relational Operators
    /**
     * @brief Compares two fractions for equality.
     * @param rhs The fraction to compare with.
     * @return True if the fractions are equal, false otherwise.
     */
    bool operator==(const Fraction &rhs) const;

    /**
     * @brief Checks if the fraction is less than another fraction.
     * @param rhs The fraction to compare with.
     * @return True if this fraction is less than rhs, false otherwise.
     */
    bool operator<(const Fraction &rhs) const;

    /**
     * @brief Compares two fractions for inequality.
     * @param rhs The fraction to compare with.
     * @return True if the fractions are not equal, false otherwise.
     */
    bool operator!=(const Fraction &rhs) const;

    /**
     * @brief Checks if the fraction is greater than another fraction.
     * @param rhs The fraction to compare with.
     * @return True if this fraction is greater than rhs, false otherwise.
     */
    bool operator>(const Fraction &rhs) const;

    /**
     * @brief Checks if the fraction is greater than or equal to another fraction.
     * @param rhs The fraction to compare with.
     * @return True if this fraction is greater than or equal to rhs, false otherwise.
     */
    bool operator>=(const Fraction &rhs) const;

    /**
     * @brief Checks if the fraction is less than or equal to another fraction.
     * @param rhs The fraction to compare with.
     * @return True if this fraction is less than or equal to rhs, false otherwise.
     */
    bool operator<=(const Fraction &rhs) const;

    // Overloaded Assignment Operator
    /**
     * @brief Assigns the values of one fraction to another.
     * @param rhs The fraction to copy values from.
     * @return A reference to this fraction after assignment.
     */
    const Fraction operator=(const Fraction &rhs);

    // Increment and Decrement Operators
    /**
     * @brief Prefix increment operator for the fraction.
     * Increases the numerator by 1.
     * @return The incremented fraction.
     */
    Fraction operator++();

    /**
     * @brief Postfix increment operator for the fraction.
     * Increases the numerator by 1.
     * @return The fraction before the increment.
     */
    Fraction operator++(int);

    /**
     * @brief Prefix decrement operator for the fraction.
     * Decreases the numerator by 1.
     * @return The decremented fraction.
     */
    Fraction operator--();

    /**
     * @brief Postfix decrement operator for the fraction.
     * Decreases the numerator by 1.
     * @return The fraction before the decrement.
     */
    Fraction operator--(int);


    // Multiplication and Division Operators
    /**
     * @brief Multiplies the fraction by an integer.
     * @param number The integer to multiply with.
     * @return The resulting fraction after multiplication.
     */
    Fraction operator*(int number);

    /**
     * @brief Multiplies the fraction by another fraction.
     * @param rhs The fraction to multiply with.
     * @return The resulting fraction after multiplication.
     */
    Fraction operator*(const Fraction &rhs);

    /**
     * @brief Divides the fraction by an integer.
     * @param number The integer to divide by.
     * @return The resulting fraction after division.
     */
    Fraction operator/(int number);

    /**
     * @brief Divides the fraction by another fraction.
     * @param rhs The fraction to divide by.
     * @return The resulting fraction after division.
     */
    Fraction operator/(const Fraction &rhs);

    // Addition and Subtraction Operators with Integers
    /**
     * @brief Adds an integer to the fraction.
     * @param number The integer to add.
     * @return The resulting fraction after addition.
     */
    Fraction operator+(const long &number);

    /**
     * @brief Subtracts an integer from the fraction.
     * @param number The integer to subtract.
     * @return The resulting fraction after subtraction.
     */
    Fraction operator-(const long &number);

    // Addition and Subtraction Operators with Fractions
    /**
     * @brief Adds another fraction to this fraction.
     * @param rhs The fraction to add.
     * @return The resulting fraction after addition.
     */
    Fraction operator+(const Fraction &rhs);

    /**
     * @brief Subtracts another fraction from this fraction.
     * @param rhs The fraction to subtract.
     * @return The resulting fraction after subtraction.
     */
    Fraction operator-(const Fraction &rhs);

    /**
     * @brief Converts the fraction to a string in the format "numerator/denominator".
     * @return A string representation of the fraction.
     */
    std::string toString() const;
};

// Stream Operator Overloads
/**
 * @brief Overloads the << operator to output a Fraction object.
 * Outputs the fraction in "numerator/denominator" format.
 * @param out The output stream to write to.
 * @param fraction The Fraction object to be outputted.
 * @return A reference to the output stream after writing the fraction.
 */
std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

/**
 * @brief Overloads the << operator to output a Fraction object pointer.
 * Outputs the fraction in "numerator/denominator" format if the pointer is not null.
 * If the pointer is null, no output is written.
 * @param out The output stream to write to.
 * @param fractionPtr Pointer to the Fraction object to be outputted.
 * @return A reference to the output stream after writing the fraction or handling a null pointer.
 */
std::ostream& operator<<(std::ostream& out, const Fraction* fractionPtr);

#endif // FRACTION_H
