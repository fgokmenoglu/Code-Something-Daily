#include <string>
#include <algorithm>

/**
 * @brief Counts the number of vowels in a given string.
 *
 * This function is designed to count the occurrences of vowels in a provided string.
 * The task specifies the following requirements:
 * 
 * @note Only lowercase letters 'a', 'e', 'i', 'o', and 'u' are considered vowels.
 * @note The letter 'y' is not considered a vowel for this task.
 * @note The input string will only contain lowercase letters and/or spaces.
 * 
 * @param inputStr The input string to be analyzed.
 * @return The count of vowels in the input string.
 *
 * @see The implementation uses a simple loop to iterate through each character
 *      of the input string and checks if it's a vowel using the find() algorithm.
 *
 * @warning The function assumes that the input string follows the specified
 *          constraints (lowercase letters and spaces only). No additional
 *          input validation is performed.
 */
int getCount(const std::string& inputStr) {
    int num_vowels = 0;
    std::string vowels = "aeiou";
    
    for (char c : inputStr) {
        if (std::find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            num_vowels++;
        }
    }
    
    return num_vowels;
}
