/*
 * Task
 * Given a string, return if all occurrences of a given letter are always immediately followed by the other given letter.
 * 
 * Worked Example
 * ("he headed to the store", "h", "e") ➞ True
 * 
 * # All occurences of "h": ["he", "headed", "the"]
 * # All occurences of "h" have an "e" after it.
 * # Return True
 * 
 * ('abcdee', 'e', 'e') ➞ False
 * 
 * # For first "e" we can get "ee"
 * # For second "e" we cannot have "ee"
 * # Return False
 *
 * Extra Examples
 * ("i found an ounce with my hound", "o", "u") ➞ True
 * ("we found your dynamite", "d", "y") ➞ False
 *
 * Notes
 * All sentences will be given in lowercase.
 */
#include <string>

bool best_friend(const std::string& txt, char a, char b) {
    // If the string is empty, return true (vacuous truth)
    if (txt.empty()) {
        return true;
    }

    // Iterate through the string up to the second-to-last character
    for (size_t i = 0; i < txt.size() - 1; ++i) {
        if (txt[i] == a) {
            // Check if the next character is not 'b'
            if (txt[i + 1] != b) {
                return false;
            }
        }
    }
    // Handle the case where the last character is 'a'
    if (txt.back() == a) {
        return false;
    }
    return true;
}
