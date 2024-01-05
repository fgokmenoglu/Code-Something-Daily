/*
 * Your task is to write a function called valid_spacing() or validSpacing() which checks if a string has valid spacing. 
 * The function should return either true or false (or the corresponding value in each language).
 * 
 * For this kata, the definition of valid spacing is one space between words, and no leading or trailing spaces. 
 * Words can be any consecutive sequence of non space characters. 
 * Below are some examples of what the function should return:
 * 
 * 'Hello world'   => true
 * ' Hello world'  => false
 * 'Hello world  ' => false
 * 'Hello  world'  => false
 * 'Hello'         => true
 * 
 * Even though there are no spaces, it is still valid because none are needed:
 * 'Helloworld'    => true
 * 'Helloworld '   => false
 * ' '             => false
 * ''              => true
 * Note - there will be no punctuation or digits in the input string, only letters.
 */
#include <string>
#include <algorithm>
 
std::string& ltrim(std::string &s) {
    auto it = std::find_if(s.begin(), s.end(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(s.begin(), it);
  
    return s;
}
 
std::string& rtrim(std::string &s) {
    auto it = std::find_if(s.rbegin(), s.rend(),
                    [](char c) {
                        return !std::isspace<char>(c, std::locale::classic());
                    });
    s.erase(it.base(), s.end());
  
    return s;
}
 
std::string& trim(std::string &s) {
    return ltrim(rtrim(s));
}

bool valid_spacing(const std::string &s) {
  if (s.empty())
    return true;
  
  if(s[0] == ' ' || s[s.length() - 1] == ' ')
    return false;
  
  for (size_t i = 0; i < s.length() - 1; ++i)
    if (s[i] == ' ' && s[i + 1] == ' ')
      return false;
  
  std::string temp = s;
  
  return trim(temp) == s;
}

// ALTERNATIVE
#include <string>

bool valid_spacing(std::string_view s) {
  return s.empty() || s.front() != ' ' && s.back() != ' ' && s.find("  ") == std::string::npos;
}
