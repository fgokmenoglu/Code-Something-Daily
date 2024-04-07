/*
 * Your job is to write a function which increments a string, to create a new string.
 * If the string already ends with a number, the number should be incremented by 1.
 * If the string does not end with a number. the number 1 should be appended to the new string.
 *
 * Examples:
 * foo -> foo1
 * foobar23 -> foobar24
 * foo0042 -> foo0043
 * foo9 -> foo10
 * foo099 -> foo100
 * 
 * Attention: If the number has leading zeros the amount of digits should be considered.
 */
#include <string>
#include <cctype>
#include <algorithm>

std::string incrementString(const std::string &str) {
    // Find the starting position of the last numeric part of the string
    auto it = std::find_if(str.rbegin(), str.rend(), [](char c) { return !std::isdigit(c); }).base();

    // Extract the non-numeric and numeric parts
    std::string prefix = std::string(str.begin(), it);
    std::string numeric = std::string(it, str.end());

    if (numeric.empty()) {
        // If there's no numeric part, just append '1'
        return prefix + '1';
    } else {
        // Increment the numeric part
        std::size_t length = numeric.length();
        int number = std::stoi(numeric);
        number++;

        // Create a format string for the correct number of leading zeros
        std::string format = "%0" + std::to_string(length) + "d";
        char buffer[32];
        std::sprintf(buffer, format.c_str(), number);

        return prefix + buffer;
    }
}
