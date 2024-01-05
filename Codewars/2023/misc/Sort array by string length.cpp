/*
 * Write a function that takes an array of strings as an argument and returns a sorted array containing the same strings, ordered from shortest to longest.
 * 
 * For example, if this array were passed as an argument:
 * 
 * ["Telescopes", "Glasses", "Eyes", "Monocles"]
 * 
 * Your function would return the following array:
 * 
 * ["Eyes", "Glasses", "Monocles", "Telescopes"]
 * 
 * All of the strings in the array passed to your function will be different lengths, so you will not have to decide how to order multiple strings of the same length.
 */
#include <vector>
#include <string>
#include <algorithm>

struct {
  bool operator()(std::string a, std::string b) const { return a.length() < b.length(); }
} customLess;

std::vector<std::string> sortByLength(std::vector<std::string> array) {
  std::sort(array.begin(), array.end(), customLess);
  
  return array;
}

// ALTERNATIVE
#include <algorithm>

class Kata {
  public:
    std::vector<std::string> sortByLength(std::vector<std::string> array) {
        std::sort(array.begin(), array.end(), [](std::string & a, std::string & b) {
          return a.size() < b.size();   
        });
      
        return array;
    }
}
