/*
 * Your task in this kata is to implement a function that calculates the sum of the integers inside a string. 
 * For example, in the string "The30quick20brown10f0x1203jumps914ov3r1349the102l4zy dog", the sum of the integers is 3635.
 *
 * Note: only positive integers will be tested.
 */
#include <string>
#include <cctype>
 
int sumOfIntegers (const std::string& str) {
    int sum = 0;
    int currentNumber = 0;

    for (char c : str) {
        if (std::isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        } else {
            sum += currentNumber;
            currentNumber = 0;
        }
    }

    // Add the last number in case the string ends with a number
    sum += currentNumber;

    return sum;
}
