/*
 * Task
 * Let's call a string cool if it is formed only by Latin letters and 
 * no two lowercase and no two uppercase letters are in adjacent positions. 
 * Given a string, check if it is cool.
 *
 * Input/Output
 * [input] string s: A string that contains uppercase letters, 
 * lowercase letters numbers and spaces.
 * 1 ≤ s.length ≤ 20.
 * [output] a boolean value: true if s is cool, false otherwise.
 *
 * Example
 * For s = "aQwFdA", the output should be true
 * For s = "aBC", the output should be false;
 * For s = "AaA", the output should be true;
 * For s = "q q", the output should be false.
 */
#include <string>
#include <cctype>

bool cool_string(const std::string& s) {
    if (s.empty()) {
        return false;  // An empty string is not considered cool
    }

    bool has_letter = false;
    char last_letter = '\0';
    
    for (char c : s) {
        if (std::isalpha(c)) {
            has_letter = true;
            if (last_letter != '\0') {
                if ((std::islower(last_letter) && std::islower(c)) || 
                    (std::isupper(last_letter) && std::isupper(c))) {
                    return false;
                }
            }
            last_letter = c;
        } else {
            return false;  // Non-alphabetic character found, string is not cool
        }
    }

    return has_letter;  // String must contain at least one letter to be cool
}

// ALTERNATIVE
#include <regex>
#include <string>

bool cool_string(const std::string& s) {
  return !(regex_search(s, std::regex("[^A-Za-z]|[A-Z]{2,}|[a-z]{2,}"))); 
}
