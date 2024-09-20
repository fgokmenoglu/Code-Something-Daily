#include <string>

/**
 * @brief Encodes lowercase vowels in a string to numbers.
 * 
 * This function replaces all lowercase vowels in the input string
 * with corresponding numbers according to the following pattern:
 * a -> 1, e -> 2, i -> 3, o -> 4, u -> 5
 * 
 * @param str The input string to encode.
 * @return std::string The encoded string.
 */
std::string encode(const std::string &str) {
    std::string result = str;
    for (char &c : result) {
        switch (c) {
            case 'a': c = '1'; break;
            case 'e': c = '2'; break;
            case 'i': c = '3'; break;
            case 'o': c = '4'; break;
            case 'u': c = '5'; break;
        }
    }
    return result;
}

/**
 * @brief Decodes numbers back to lowercase vowels in a string.
 * 
 * This function replaces all numbers in the input string
 * with corresponding lowercase vowels according to the following pattern:
 * 1 -> a, 2 -> e, 3 -> i, 4 -> o, 5 -> u
 * 
 * @param str The input string to decode.
 * @return std::string The decoded string.
 */
std::string decode(const std::string &str) {
    std::string result = str;
    for (char &c : result) {
        switch (c) {
            case '1': c = 'a'; break;
            case '2': c = 'e'; break;
            case '3': c = 'i'; break;
            case '4': c = 'o'; break;
            case '5': c = 'u'; break;
        }
    }
    return result;
}

// Alternative approach:
/*
#include <map>
#include <string>

std::string encode(std::string s) {
  static std::map<char, char> d {{'a', '1'}, {'e', '2'}, {'i', '3'}, {'o', '4'}, {'u', '5'}};
  for (auto &x : s) if (d.count(x)) x = d[x];
  return s;
}

std::string decode(std::string s) {
  for (auto &x : s) if ('0' < x && x < '6') x = "aeiou"[x - '1'];
  return s;
}
*/
