#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

/* Task Description:
 * Given a string of words, you need to find the highest scoring word.
 * Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.
 * For example, the score of abad is 8 (1 + 2 + 1 + 4).
 * You need to return the highest scoring word as a string.
 * If two words score the same, return the word that appears earliest in the original string.
 * All letters will be lowercase and all inputs will be valid.
 */

std::string highestScoringWord(const std::string &str)
{
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;
    
    // Split the input string into words
    while (iss >> word) {
        words.push_back(word);
    }
    
    std::string highestWord;
    int highestScore = 0;
    
    for (const auto &w : words) {
        int score = 0;
        for (char c : w) {
            score += c - 'a' + 1;  // Calculate score for each letter
        }
        
        if (score > highestScore) {
            highestScore = score;
            highestWord = w;
        }
    }
    
    return highestWord;
}
