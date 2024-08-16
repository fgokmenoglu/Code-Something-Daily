#include <string>
#include <algorithm>

/* Task Description:
 * Re-order the characters of a string, so that they are concatenated into a new string
 * in "case-insensitively-alphabetical-order-of-appearance" order.
 * Whitespace and punctuation shall simply be removed!
 * The input is restricted to contain no numerals and only words containing
 * the english alphabet letters.
 * 
 * Example:
 * alphabetized("The Holy Bible") // "BbeehHilloTy"
 */

std::string alphabetized(const std::string& str){
  auto s = str;
  s.erase(std::remove_if(s.begin(), s.end(), [](auto c){ return !isalpha(c); }), s.end());
  std::stable_sort(s.begin(), s.end(), [](auto a, auto b){ return std::tolower(a) < std::tolower(b);});
  return s;
}
