/*
 * Given a string and an array of integers representing indices, capitalize all letters at the given indices.
 * 
 * For example:
 * 
 * capitalize("abcdef",[1,2,5]) = "aBCdeF"
 * capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
 * The input will be a lowercase string with no spaces and an array of digits.
 */
#include <string>
#include <algorithm> // find()
#include <cctype> // toupper()

std::string capitalize(std::string s, std::vector<int> idxs) {
  std::string output = "";
  
  for (int i = 0; i < s.length(); i++) {
    if (std::find(idxs.begin(), idxs.end(), i) != idxs.end()) {
      output.push_back(toupper(s[i]));
      continue;
    }
    
    output.push_back(s[i]);
  }
  
  return output;
}

// ALTERNATIVE
#include<string>
#include <algorithm> // for_each()
#include<cctype> // toupper()

std::string capitalize(std::string s, std::vector<int> idxs) {
  for_each(idxs.begin(), idxs.end(), [&](auto const i) { if(i < s.size()) s[i] = toupper(s[i]); });
  
  return s;
}
