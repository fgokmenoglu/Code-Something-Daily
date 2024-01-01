/*
 * In cryptanalysis, words patterns can be a useful tool in cracking simple ciphers.
 * A word pattern is a description of the patterns of letters occurring in a word, where each letter is given an integer code in order of appearance. 
 * So the first letter is given the code 0, and second is then assigned 1 if it is different to the first letter or 0 otherwise, and so on.
 * As an example, the word "hello" would become "0.1.2.2.3". 
 * For this task case-sensitivity is ignored, so "hello", "helLo" and "heLlo" will all return the same word pattern.
 * Your task is to return the word pattern for a given word. 
 * All words provided will be non-empty strings of alphabetic characters only, i.e. matching the regex "[a-zA-Z]+".
 */
#include <string>
#include <unordered_map>
#include <cctype>

std::string wordPattern(const std::string &word) {
    std::unordered_map<char, int> charMap;
    std::string pattern = "";
    int code = 0;

    for (char ch : word) {
        // Convert to lowercase
        ch = std::tolower(ch);

        // If the character is not in the map, assign a new code
        if (charMap.find(ch) == charMap.end()) {
            charMap[ch] = code++;
        }

        // Append the code to the pattern string
        if (!pattern.empty())
            pattern += ".";

        pattern += std::to_string(charMap[ch]);
    }

    return pattern;
}
