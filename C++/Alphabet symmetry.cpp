/*
 * Consider the word "abode". We can see that the letter a is in position 1 and b is in position 2. In the alphabet, a and b are also in positions 1 and 2. Notice also that d and e in abode occupy the positions they would occupy in the alphabet, which are positions 4 and 5.
 * 
 * Given an array of words, return an array of the number of letters that occupy their positions in the alphabet for each word. For example,
 * 
 * solve(["abode","ABc","xyzD"]) = [4, 3, 1]
 * See test cases for more examples.
 * 
 * Input will consist of alphabet characters, both uppercase and lowercase. No spaces.
 */
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<int> solve(const std::vector<std::string>& arr) {  
  std::vector<int> output = {};
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  int temp1 = 0;
  
  for (size_t i = 0; i < arr.size(); i++) {
    std::string temp2 = arr[i];
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), [](unsigned char c) { return std::tolower(c); });
    
    for (size_t j = 0; j < temp2.length(); j++) {
      if (temp2[j] == alphabet[j])
        temp1 += 1;
    }
    
    output.push_back(temp1);
    temp1 = 0;
  }
  
  return output;
}

// ALTERNATIVE
#include <vector>
#include <string>
#include <cctype>

std::vector<int> solve(std::vector<std::string> v) {
  std::vector<int> result(v.size());
  
  for (int i = 0; i < v.size(); i++)
    for (int j = 0; j < v[i].length(); j++) 
      if (toupper(v[i][j]) - 65 == j)
        result[i]++;
  
  return result;
}
