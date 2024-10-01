#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * @brief Identifies if a string is composed of repeating subpatterns
 * 
 * This function analyzes the input string to determine if it's composed
 * of repeating subpatterns. If a subpattern is found, it returns the 
 * subpattern with its characters sorted. If no subpattern is found, 
 * it returns the entire input string with its characters sorted.
 * 
 * @param str The input string to analyze
 * @return std::string The identified subpattern or the entire string, with characters sorted
 * 
 * @note There is no deterministic way to identify the original subpattern
 *       among all possible permutations of a fitting subpattern. Therefore,
 *       this function always returns a subpattern with sorted characters.
 * 
 * @note The case where the subpattern equals the entire input string
 *       (i.e., no repetition) is treated as an edge case, and the function
 *       returns the entire string with its characters sorted.
 * 
 * Examples:
 * - hasSubpattern("a") returns "a" (no repeated pattern, just one character)
 * - hasSubpattern("aaaa") returns "a" (just one character repeated)
 * - hasSubpattern("abcd") returns "abcd" (base pattern equals the string itself, no repetitions)
 * - hasSubpattern("babababababababa") returns "ab" (repeated subpattern, characters sorted)
 * - hasSubpattern("bbabbaaabbaaaabb") returns "ab" (same as above, just shuffled)
 */
std::string hasSubpattern(const std::string& str) {
    int n = str.length();
    if (n <= 1) return str;

    // Count character frequencies
    std::unordered_map<char, int> char_count;
    for (char c : str) char_count[c]++;

    // Find the GCD of all character frequencies
    int gcd = char_count.begin()->second;
    for (const auto& pair : char_count) {
        gcd = std::__gcd(gcd, pair.second);
    }

    // If GCD is 1, no repeating subpattern exists
    if (gcd == 1) {
        std::string sorted_str = str;
        std::sort(sorted_str.begin(), sorted_str.end());
        return sorted_str;
    }

    // Construct the subpattern
    std::string subpattern;
    for (const auto& pair : char_count) {
        subpattern.append(pair.second / gcd, pair.first);
    }

    // Sort the subpattern
    std::sort(subpattern.begin(), subpattern.end());

    return subpattern;
}
