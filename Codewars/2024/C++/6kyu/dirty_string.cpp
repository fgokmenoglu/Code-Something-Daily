/*
 * The input is a string which consists of two positive numbers (doubles) 
 * and exactly one operator like +, -, * or / always between these numbers. 
 * The string is dirty, which means that there are different characters inside too, 
 * not only numbers and the operator. 
 * You have to combine all digits left and right, perhaps with "." inside (doubles), 
 * and to calculate the result which has to be rounded to an integer and converted to a string at the end. 
 * Below is an example:
 *
 * Input: "gdfgdf234dg54gf*23oP42"
 * Output: "54929268" (because 23454*2342=54929268)
 */
#include <string>
#include <cctype>
#include <cmath>
#include <stdexcept>

std::string calculateString(std::string calcIt) {
    std::string num1, num2;
    char op = '\0';
    bool foundOp = false;

    // Extract numbers and operator
    for (char c : calcIt) {
        if (std::isdigit(c) || c == '.') {
            if (!foundOp) {
                num1 += c;
            } else {
                num2 += c;
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            op = c;
            foundOp = true;
        }
    }

    // Convert strings to doubles
    double n1 = std::stod(num1);
    double n2 = std::stod(num2);

    // Perform calculation
    double result;
    switch (op) {
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '/':
            if (n2 == 0) {
                throw std::runtime_error("Division by zero");
            }
            result = n1 / n2;
            break;
        default:
            throw std::runtime_error("Invalid operator");
    }

    // Round to nearest integer and convert to string
    return std::to_string(std::llround(result));
}
