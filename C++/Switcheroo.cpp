/*
 * Given a string made up of letters a, b, and/or c, switch the position of letters a and b (change a to b and vice versa). Leave any incidence of c untouched.
 *
 * Example:
 *
 * 'acb' --> 'bca'
 * 'aabacbaa' --> 'bbabcabb'
 */
#include <string>

std::string switcheroo(const std::string &s) {
  std::string result = s;
  
  for (auto ch(result.begin()); ch != result.end(); ch++)
    if (*ch == 'a')
      *ch = 'b';
    else if (*ch == 'b')
      *ch = 'a';
  
  return result;
}

// ALTERNATIVE
#include <string>
#include <algorithm>

std::string switcheroo(const std::string &s) {
  std::string r = s;
  transform(r.begin(),r.end(),r.begin(),[](char c) {return c == 'a' ? 'b' : c == 'b' ? 'a' : c;});
  return r;
}
