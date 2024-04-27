/*
 * You are given a string of words (x), 
 * for each word within the string 
 * you need to turn the word 'inside out'. 
 * By this I mean the internal letters will move out, 
 * and the external letters move toward the centre.
 * If the word is even length, all letters will move. 
 * If the length is odd, you are expected to leave 
 * the 'middle' letter of the word where it is.
 * An example should clarify:
 *'taxi' would become 'atix' 'taxis' would become 'atxsi'
 */
#include <iostream>
#include <sstream>
#include <vector>

std::string insideOut(const std::string& x) {
    std::istringstream iss(x);
    std::vector<std::string> words;
    std::string word;
    
    // Split the input string into words
    while (iss >> word) {
        words.push_back(word);
    }
    
    // Transform each word
    for (std::string& w : words) {
        int len = w.size();
        if (len % 2 == 0) {
            // Even length: reverse both halves
            std::reverse(w.begin(), w.begin() + len / 2);
            std::reverse(w.begin() + len / 2, w.end());
        } else {
            // Odd length: reverse around the middle character
            std::reverse(w.begin(), w.begin() + len / 2);
            std::reverse(w.begin() + len / 2 + 1, w.end());
        }
    }
    
    // Reassemble the words back into a single string
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) result += " ";  // Add space between words
        result += words[i];
    }
    
    return result;
}
