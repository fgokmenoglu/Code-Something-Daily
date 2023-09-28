/*
 * Given a string, capitalize the letters that occupy even indexes and odd indexes separately, and return as shown below. Index 0 will be considered even.
 * 
 * For example, capitalize("abcdef") = ['AbCdEf', 'aBcDeF']. See test cases for more examples.
 * 
 * The input will be a lowercase string with no spaces.
 */
std::pair<std::string, std::string> capitalize(const std::string &s) {
  std::string first, second;
  
  for (size_t i = 0; i < s.length(); i++)
    if(i % 2 == 0) {
      first.push_back(toupper(s[i]));
      second.push_back(s[i]);
    } else {
      first.push_back(s[i]);
      second.push_back(toupper(s[i]));
    }   
  
  return {first, second};
}
