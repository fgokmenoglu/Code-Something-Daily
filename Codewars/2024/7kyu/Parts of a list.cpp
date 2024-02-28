/*
 * Write a function partlist that gives all the ways to divide a list (an array) of at least two elements into two non-empty parts.
 * 
 * Each two non empty parts will be in a pair (or an array for languages without tuples or a structin C - C: see Examples test Cases - )
 * Each part will be in a string
 * Elements of a pair must be in the same order as in the original array.
 *
 * Example:
 * a = {"az", "toto", "picaro", "zone", "kiwi"} -->
 * {{"az", "toto picaro zone kiwi"}, {"az toto", "picaro zone kiwi"}, {"az toto picaro", "zone kiwi"}, {"az toto picaro zone", "kiwi"}}
 */
#include <vector>
#include <utility>
#include <string>

class PartList {
public:
  static std::vector<std::pair<std::string, std::string>> partlist(std::vector<std::string> &arr) {
    std::vector<std::pair<std::string, std::string>> out;
    
    for (size_t i = 1; i < arr.size(); ++i) {
      std::string firstPart, secondPart;
      
      for (size_t j = 0; j < i; ++j)
        firstPart += (j > 0 ? " " : "") + arr[j];

      for (size_t j = i; j < arr.size(); ++j)
        secondPart += (j > i ? " " : "") + arr[j];

      out.push_back(std::make_pair(firstPart, secondPart));
    }
    
    return out;
  }
};

// ALTERNATIVE
#include <vector>
#include <utility>
#include <string>
#include <numeric>

using namespace std;

class PartList
{
public:
  static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr) {
    vector<pair<string, string>> result;
    auto combine = [](string a, string b) { return a + ' ' + b; };
    
    for (int i = 1; i < arr.size(); i++) {
      result.emplace_back(
        accumulate(arr.begin() + 1, arr.begin() + i, arr[0], combine),
        accumulate(arr.begin() + i + 1,  arr.end(), arr[i], combine));
    }
      
    return result;
  }
};
