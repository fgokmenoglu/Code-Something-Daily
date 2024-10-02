#include <string>

/**
 * @brief Removes all vowels from a given string.
 * 
 * This function takes a string as input and returns a new string with all
 * vowels removed. For the purpose of this function, 'y' is not considered
 * a vowel.
 * 
 * @param str The input string from which vowels will be removed.
 * @return std::string A new string with all vowels removed.
 * 
 * @example
 * Input: "This website is for losers LOL!"
 * Output: "Ths wbst s fr lsrs LL!"
 */
std::string disemvowel(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && 
            tolower(c) != 'o' && tolower(c) != 'u') {
            result += c;
        }
    }
    return result;
}

//ALTERNATIVE
#include <string>
#include <regex>
std::string disemvowel(std::string str) {
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}
