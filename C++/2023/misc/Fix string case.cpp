/*
 * In this Kata, you will be given a string that may have mixed uppercase and lowercase letters and your task is to convert that string to either lowercase only or uppercase only based on:
 * 
 * make as few changes as possible.
 * if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.
 * For example:
 * 
 * solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
 * solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
 * solve("coDE") = "code". Upper == lowercase. Change all to lowercase.
 */
#include <string>
#include <algorithm>

std::string solve(const std::string& str) {
  std::string result = str;
  int lowerCount = 0, upperCount = 0;
  
  for (auto ch(result.begin()); ch != result.end(); ch++)
    if (*ch >= 65 && *ch <= 90)
      upperCount++;
    else if (*ch >= 97 && *ch <= 122)
      lowerCount++;
  
  if (upperCount > lowerCount)
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);  
  else
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
  
  return result;
}

// ALTERNATIVE
#include <string>
#include <algorithm>

std::string solve(const std::string& str) {
  std::string result = str;
  bool bLower = result.size() <= 2 * std::count_if(result.begin(), result.end(), ::islower);
  
  std::transform(result.begin(), result.end(), result.begin(), [&] (auto ch) {
    return bLower ? std::tolower(ch) : std::toupper(ch);
  });
  
  return result;
}
