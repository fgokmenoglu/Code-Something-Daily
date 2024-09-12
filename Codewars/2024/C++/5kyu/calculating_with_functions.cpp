#include <functional>

/*
 * Calculator Functions Implementation
 * 
 * This module provides a set of functions for performing simple arithmetic
 * calculations using a function chaining approach. It allows for intuitive
 * expression of mathematical operations.
 *
 * Key Features:
 * - Functions for numbers 0 through 9
 * - Basic arithmetic operations: addition, subtraction, multiplication, division
 * - Chained function calls to represent calculations
 * 
 * Usage Examples:
 *   seven(times(five()))      // Computes 7 * 5 = 35
 *   four(plus(nine()))        // Computes 4 + 9 = 13
 *   eight(minus(three()))     // Computes 8 - 3 = 5
 *   six(divided_by(two()))    // Computes 6 / 2 = 3
 *
 * Notes:
 * - Each calculation involves exactly one operation and two numbers
 * - The outermost function represents the left operand
 * - The innermost function represents the right operand
 * - Division is implemented as integer division
 */

// Function type for arithmetic operations
using Operation = std::function<int(int)>;

// Number functions (0-9)
auto zero() { return 0; }
auto one() { return 1; }
auto two() { return 2; }
auto three() { return 3; }
auto four() { return 4; }
auto five() { return 5; }
auto six() { return 6; }
auto seven() { return 7; }
auto eight() { return 8; }
auto nine() { return 9; }

// Overloaded number functions that accept an operation
auto zero(Operation op) { return op(0); }
auto one(Operation op) { return op(1); }
auto two(Operation op) { return op(2); }
auto three(Operation op) { return op(3); }
auto four(Operation op) { return op(4); }
auto five(Operation op) { return op(5); }
auto six(Operation op) { return op(6); }
auto seven(Operation op) { return op(7); }
auto eight(Operation op) { return op(8); }
auto nine(Operation op) { return op(9); }

// Arithmetic operations

/**
 * Addition operation
 * @param x The right operand
 * @return A lambda function that adds x to its argument
 */
auto plus(int x) {
    return [x](int y) { return y + x; };
}

/**
 * Subtraction operation
 * @param x The right operand
 * @return A lambda function that subtracts x from its argument
 */
auto minus(int x) {
    return [x](int y) { return y - x; };
}

/**
 * Multiplication operation
 * @param x The right operand
 * @return A lambda function that multiplies its argument by x
 */
auto times(int x) {
    return [x](int y) { return y * x; };
}

/**
 * Division operation (integer division)
 * @param x The right operand
 * @return A lambda function that divides its argument by x
 */
auto divided_by(int x) {
    return [x](int y) { return y / x; };
}
