#include <string>
#include <sstream>
#include <limits>

/**
 * @brief Finds the length of the shortest word in a given string.
 * 
 * @details This function takes a string of words and returns the length
 *          of the shortest word(s) in it. The string will never be empty,
 *          and there's no need to account for different data types.
 * 
 * @param str A string containing one or more words.
 * @return int The length of the shortest word in the string.
 */
int find_short(std::string str)
{
    std::istringstream iss(str);
    std::string word;
    int shortest = std::numeric_limits<int>::max();
    
    while (iss >> word) {
        int length = word.length();
        if (length < shortest) {
            shortest = length;
        }
    }
    
    return shortest;
}
