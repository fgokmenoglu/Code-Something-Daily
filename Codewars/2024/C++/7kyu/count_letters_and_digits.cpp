/*
 * Create a method that can determine how many letters 
 * (both uppercase and lowercase ASCII letters) and 
 * digits are in a given string.
 *
 * Example:
 * "hel2!lo" --> 6
 * "wicked .. !" --> 6
 * "!?..A" --> 1
 */
#include <cctype>

int countLettersAndDigits(std::string input) {
    int out = 0;
    
    for (auto ch : input)
        if (isalpha(ch) || isdigit(ch))
          out += 1;
  
    return out;
}

// ALTERNATIVE
int countLettersAndDigits(std::string input) {
    return count_if(input.begin(), input.end(), isalnum);
}
