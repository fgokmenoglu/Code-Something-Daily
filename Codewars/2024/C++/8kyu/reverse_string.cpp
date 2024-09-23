#include <string>
#include <algorithm>
#include <sstream>

/**
 * @brief Reverses all words in a given string.
 * 
 * This function takes a string as input and reverses the order of all words
 * within the string. Words are defined as sequences of characters separated
 * by exactly one space. The function preserves the order of characters within
 * each word, only reversing the order of the words themselves.
 * 
 * @param str The input string containing words to be reversed.
 *            Must not have leading or trailing spaces.
 * @return std::string A new string with all words reversed.
 * 
 * @note Words are separated by exactly one space.
 * @note There are no leading or trailing spaces in the input string.
 * @note The function preserves the case of letters in each word.
 * 
 * @example
 * Input: "The greatest victory is that which requires no battle"
 * Output: "battle no requires which that is victory greatest The"
 */
std::string reverse_words(const std::string& str) {
    std::istringstream iss(str);
    std::string word, result;
    std::vector<std::string> words;

    // Split the input string into words
    while (iss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    std::reverse(words.begin(), words.end());

    // Join the words back into a single string
    for (const auto& w : words) {
        if (!result.empty()) {
            result += " ";
        }
        result += w;
    }

    return result;
}
