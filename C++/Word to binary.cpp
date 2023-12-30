/*
 * Write a function that takes a string and returns an array containing binary numbers equivalent to the ASCII codes of the characters of the string. 
 * The binary strings should be eight digits long.
 * Example: 'man' should return [ '01101101', '01100001', '01101110' ]
 */
#include <vector>
#include <string>
#include <bitset>

std::vector<std::string> word_to_bin(std::string word) {
  std::vector<std::string> output = {};
  std::string binaryStr = "";
  
  for (size_t i = 0; i < word.length(); ++i) {
    binaryStr = std::bitset<8>(word[i]).to_string();
    output.push_back(binaryStr);
  }
  
  return output;
}

// ALTERNATIVE
#include <vector>
#include <string>
#include <bitset>

constexpr size_t ascii_bits = 8;

std::vector<std::string> word_to_bin(const std::string &word) {
  std::vector<std::string> result;
  result.reserve(word.size());
    
  for (const char &ch : word) 
    result.push_back(std::bitset<ascii_bits>(ch).to_string());
  
  return result;
}
