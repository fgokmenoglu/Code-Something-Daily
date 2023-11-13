/*
 * Write a function that takes a string and an an integer n as parameters and returns a list of all words that are longer than n.
 * 
 * Example:
 * 
 * With input "The quick brown fox jumps over the lazy dog", 4
 * Return ['quick', 'brown', 'jumps']
 */
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  std::stringstream ss(sentence);
  std::vector<std::string> tokens = {};
  std::string token = "";
  std::vector<std::string> output = {};
  
  while (getline(ss, token, ' '))
    tokens.push_back(token);
  
  for (size_t i = 0; i < tokens.size(); i++)
    if (tokens[i].length() > n)
      output.push_back(tokens[i]);
      
  return output;
}

// ALTERNATIVE
#include <vector>
#include <string>
#include <istream>

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  std::vector<std::string> r;
  std::istringstream ss(sentence);
  std::string s;
  while (ss >> s) if (s.size() > n) r.push_back(s);
  return r;
}
