/*
 * Given a string indicating a range of letters, 
 * return a string which includes all the letters in that range, including the last letter.
 * Note that if the range is given in capital letters, 
 * return the string in capitals also!
 *
 * Examples
 * "a-z" ➞ "abcdefghijklmnopqrstuvwxyz"
 * "h-o" ➞ "hijklmno"
 * "Q-Z" ➞ "QRSTUVWXYZ"
 * "J-J" ➞ "J"
 *
 * Notes
 * A hyphen will separate the two letters in the string.
 * Both letters will be the same case and 
 * the second letter will not be before the first alphabetically.
 */
#include <string>

std::string gimme_the_letters(const std::string& range) {
    // Ensure the string is in the expected format
    if (range.size() != 3 || range[1] != '-') {
        return "";  // Return empty string for invalid format
    }

    // Extract the start and end characters from the string
    char start = range[0];
    char end = range[2];

    // Initialize a result string
    std::string result;

    // Generate all characters from start to end
    for (char c = start; c <= end; c++) {
        result += c;  // Append each character to the result string
    }

    // Return the resultant string
    return result;
}
