/*
 * Given a string "abc" and assuming that each letter in the string has a value equal to its position in the alphabet, our string will have a value of 1 + 2 + 3 = 6. This means that: a = 1, b = 2, c = 3 ....z = 26.
 *
 * You will be given a list of strings and your task will be to return the values of the strings as explained above multiplied by the position of that string in the list. For our purpose, position begins with 1.
 *
 * nameValue ["abc","abc abc"] should return [6,24] because of [ 6 * 1, 12 * 2 ]. Note how spaces are ignored.
 *
 * "abc" has a value of 6, while "abc abc" has a value of 12. Now, the value at position 1 is multiplied by 1 while the value at position 2 is multiplied by 2.
 * 
 * Input will only contain lowercase characters and spaces.
 */
#include <vector>
#include <string>

std::vector<int> wordValue(std::vector <std::string> arr) {
	std::string letters = " abcdefghijklmnopqrstuvwxyz";
  std::vector<int> output = {};
  size_t temp = 0, index = 0, temp2 = 0;
  
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[i].length(); j++) {
      index = letters.find(arr[i][j]);
      
      if (index != std::string::npos)
        temp += index;
      else {
        temp2 += temp;
        temp = 0;
      }
    }
    temp += temp2;
    temp2 = 0;
    temp *= i + 1;
    output.push_back(temp);
    temp = 0;
  }
  
  return output;
}

// ALTERNATIVE
#include <vector>
#include <string>

std::vector<int> wordValue(std::vector <std::string> arr) {
	std::vector<int> vec {};
  
  for (unsigned long i = 0; i < arr.size(); i++) {
    std::string tempstr = arr[i];      
    int sum = 0;
    
    for (auto c : tempstr)
      if (c != ' ') sum += c - 'a' + 1;
    
    vec.push_back(sum * (i + 1));
  }
  
  return vec;
}
