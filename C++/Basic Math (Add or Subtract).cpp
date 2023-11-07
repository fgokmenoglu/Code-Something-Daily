/*
 * In this kata, you will do addition and subtraction on a given string. The return value must be also a string.
 * 
 * Note: the input will not be empty.
 * 
 * Examples
 * "1plus2plus3plus4"  --> "10"
 * "1plus2plus3minus4" -->  "2"
 */
#include <string>

std::string calculate(std::string str) {
  int result = 0, i = 0;
  std::string temp = "";
  
  do {
    temp += str[i++]; 
  } while (str[i] != '\0' && (str[i] != 'p' || str[i] != 'n'));
  
  result = std::stoi(temp);
  
  for (size_t i = 1; i < str.length(); i++)
    if (str[i] == 'p') {
      temp = "";
      int j = i + 4;
      
      do {
        temp += str[j++]; 
      } while (str[j] != '\0' && (str[j] != 'p' || str[j] != 'n'));
      
      result += std::stoi(temp);
    }
    else if (str[i] == 'm') {
      temp = "";
      int j = i + 5;
      
      do {
        temp += str[j++]; 
      } while (str[j] != '\0' && (str[j] != 'p' || str[j] != 'n'));
      
      result -= std::stoi(temp);
    }
  
  return std::to_string(result);
}
