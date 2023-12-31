/*
 * Create a function that takes a string argument and returns that same string with all vowels removed (vowels are "a", "e", "i", "o", "u").
 * 
 * Example (Input --> Output)
 * 
 * "drake" --> "drk"
 * "aeiou" --> ""
 * remove_vowels("drake") // => "drk"
 * remove_vowels("aeiou") // => ""
 */
#include <string>

std::string remove_vowels(const std::string& str) {
  std::string output = str;
  std::string vowels = "aeiou";
  output.erase(std::remove_if(output.begin(), output.end(), [&](char ch) { return vowels.find(ch) != std::string::npos;}));
  return output;
}
