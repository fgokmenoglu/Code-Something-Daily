/*
 * Given an array of numbers (in string format), you must return a string. The numbers correspond to the letters of the alphabet in reverse order: a=26, z=1 etc. 
 * You should also account for '!', '?' and ' ' that are represented by '27', '28' and '29' respectively.
 * All inputs will be valid.
 */
#include <string>
#include <vector>

std::string switcher(const std::vector<std::string>& arr) {
  std::string output = "";
  
  for (unsigned long i = 0; i < arr.size(); i++) {
    if (arr[i] == "27") {
      output.push_back('!');
      continue;
    } else if (arr[i] == "28") {
      output.push_back('?');
      continue;      
    } else if(arr[i] == "29") {
      output.push_back(' ');
      continue;      
    }
    
    output.push_back(123 - stoi(arr[i]));
  }
  
  return output;
}

// ALTERNATIVE
#include <string>
#include <vector>

std::string switcher(const std::vector<std::string>& arr) {
  std::string s = " zyxwvutsrqponmlkjihgfedcba!? ";
  std::string r;
  
  for (const std::string& n: arr) 
    r += s[stoi(n)];
  
  return r;
}
