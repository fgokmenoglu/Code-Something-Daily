#include <string>
#include <cctype>
#include <sstream>

/* Task Description:
 *
 * In this kata you are required to, given a string, replace every letter with its position in the alphabet.
 * 
 * If anything in the text isn't a letter, ignore it and don't return it.
 * 
 * "a" = 1, "b" = 2, etc.
 * 
 * Example
 * Input = "The sunset sets at twelve o' clock."
 * Output = "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11"
 */

std::string alphabet_position(const std::string &text) {
    std::stringstream result;
    bool first = true;
    
    for (char c : text) {
        if (std::isalpha(c)) {
            int position = std::tolower(c) - 'a' + 1;
            if (!first) {
                result << " ";
            }
            result << position;
            first = false;
        }
    }
    
    return result.str();
}
