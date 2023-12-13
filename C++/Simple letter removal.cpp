/*
 * In this Kata, you will be given a lower case string and your task will be to remove k characters from that string using the following rule:
 * 
 * - first remove all letter 'a', followed by letter 'b', then 'c', etc...
 * - remove the leftmost character first.
 * For example: 
 * solve('abracadabra', 1) = 'bracadabra' # remove the leftmost 'a'.
 * solve('abracadabra', 2) = 'brcadabra'  # remove 2 'a' from the left.
 * solve('abracadabra', 6) = 'rcdbr'      # remove 5 'a', remove 1 'b' 
 * solve('abracadabra', 8) = 'rdr'
 * solve('abracadabra',50) = ''
 */
#include <string>

std::string solve(const std::string &s, unsigned k) {
    std::string output = s;

    // Iterate over the alphabet starting from 'a'
    for (char ch = 'a'; ch <= 'z' && k > 0; ++ch) {
        size_t foundPos;

        // While there are characters to remove and the character is found in the string
        while (k > 0 && (foundPos = output.find(ch)) != std::string::npos) {
            // Remove the leftmost occurrence of the character
            output.erase(foundPos, 1);
            --k;
        }
    }

    return output;
}

// ALTERNATIVE
#include <string>
#include <map>

std::string solve(const std::string &s, unsigned k) {
  std::string output = s;
  std::map<char, long> letterCounts;
  
  for(auto ch : output)
    letterCounts[ch]++;
  
  for(auto it : letterCounts) {
    while(letterCounts[it.first] > 0 && k > 0) {
      auto idx = output.find(it.first);
      output.erase(idx,1);
      k--;
      letterCounts[it.first]--;
    }

    if(output.empty())
      return "";
    
    if(k == 0)
      return output;
  }
}
