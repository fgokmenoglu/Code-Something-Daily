#include <map>
#include <string>

/**
 * @brief Counts the occurrences of each character in a given string.
 *
 * This function takes a string as input and returns a map where:
 * - Each key is a character from the input string.
 * - Each value is the number of occurrences of that character.
 *
 * @param string The input string to be analyzed.
 * @return std::map<char, unsigned> A map containing character counts.
 *         If the input string is empty, an empty map is returned.
 *
 * @example
 *   Input: "aba"
 *   Output: {'a': 2, 'b': 1}
 *
 * @example
 *   Input: ""
 *   Output: {}
 */
std::map<char, unsigned> count(const std::string& string) {
    std::map<char, unsigned> charCount;
    
    // Iterate through each character in the string
    for (char c : string) {
        // Increment the count for the current character
        // If the character is not in the map, it's automatically added with a count of 1
        charCount[c]++;
    }
    
    // The function will return an empty map if the input string is empty
    return charCount;
}
