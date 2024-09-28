#include <vector>
#include <string>

/**
 * @brief Combines an array of words into a single sentence.
 *
 * This function takes a vector of words and concatenates them into a single
 * sentence, adding spaces between words but not at the beginning or end of
 * the sentence. It does not perform any sanitization of words or add any
 * punctuation.
 *
 * @param words A vector of strings, each representing a word.
 * @return A string containing all input words combined into a sentence.
 *
 * Example:
 * @code
 * std::vector<std::string> words = {"hello", "world", "this", "is", "great"};
 * std::string result = smash(words);
 * // result will be "hello world this is great"
 * @endcode
 */
std::string smash(const std::vector<std::string>& words)
{
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) {
            result += " ";
        }
        result += words[i];
    }
    return result;
}
