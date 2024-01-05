/*
 * In this Kata, you will be given a string and your task will be to return a list of ints detailing the count of uppercase letters, lowercase, numbers and special characters, as follows.
 *
 * Solve("*'&ABCDabcde12345") = [4,5,5,3]. 
 * --the order is: uppercase letters, lowercase, numbers and special characters.
 */
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<int> solve(std::string s) {
  std::vector<int> output = {};
  int countUpper = 0, countLower = 0, countNumber = 0, countSpecial = 0;
  
  countUpper = std::count_if(s.begin(), s.end(), [](const char ch) { return std::isupper(ch); });
  countLower = std::count_if(s.begin(), s.end(), [](const char ch) { return std::islower(ch); });
  countNumber = std::count_if(s.begin(), s.end(), [](const char ch) { return std::isdigit(ch); });
  countSpecial = std::count_if(s.begin(), s.end(), [](const char ch) { return !std::isalnum(ch); });
  
  output = {countUpper, countLower, countNumber, countSpecial};
  return output;
}

// ALTERNATIVE
#include <string>
#include <vector>
#include <cctype>

std::vector<int> solve(const std::string &s) {
    int countUpper = 0, countLower = 0, countDigit = 0, countSpecial = 0;

    for (char ch : s) {
        if (std::isupper(ch)) {
            ++countUpper;
        } else if (std::islower(ch)) {
            ++countLower;
        } else if (std::isdigit(ch)) {
            ++countDigit;
        } else {
            ++countSpecial;
        }
    }

    std::vector<int> result = {countUpper, countLower, countDigit, countSpecial};
    return result;
}
