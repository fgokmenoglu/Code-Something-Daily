/*
 * In this kata you need to build a function to return either true/True or false/False 
 * if a string can be seen as the repetition of a simpler/shorter subpattern or not.
 *
 * For example:
 *
 * hasSubpattern("a") == false; //no repeated pattern
 * hasSubpattern("aaaa") == true; //created repeating "a"
 * hasSubpattern("abcd") == false; //no repeated pattern
 * hasSubpattern("abababab") == true; //created repeating "ab"
 * hasSubpattern("ababababa") == false; //cannot be entirely reproduced repeating a pattern
 *
 * Strings will never be empty and can be composed of any character 
 * (just consider upper- and lowercase letters as different entities)
 * and can be pretty long (keep an eye on performances!).
 */
#include <string>

bool hasSubpattern(const std::string& str) {
    int n = str.size();
    // Loop through possible subpattern lengths
    for (int len = 1; len <= n / 2; ++len) {
        // Check if the length of the string is divisible by the subpattern length
        if (n % len == 0) {
            // Generate the subpattern
            std::string subpattern = str.substr(0, len);
            // Check if repeating the subpattern forms the original string
            std::string repeated = "";
            for (int i = 0; i < n / len; ++i) {
                repeated += subpattern;
            }
            if (repeated == str) {
                return true;
            }
        }
    }
    return false;
}
