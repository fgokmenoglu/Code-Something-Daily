/*
 * Write a function to convert a name into initials. 
 * This kata strictly takes two words with one space in between them.
 * The output should be two capital letters with a dot separating them.
 * 
 * It should look like this:
 * Sam Harris => S.H
 * patrick feeney => P.F
 */
#include <string>
#include <cctype>

std::string abbrevName(std::string name) {
  std::string first_name = name.substr(0, name.find(' '));
  std::string last_name = name.substr(name.find(' ') + 1);
  std::string out = "";
  
  out.push_back(std::toupper(first_name[0]));
  out.push_back('.');
  out.push_back(std::toupper(last_name[0]));
  
  return out;
}

// ALTERNATIVE
#include <string>
#include <cctype>

std::string abbrevName(std::string name) {
  std::string out = "";
  
  out += toupper(name[0]);
  out += '.';
  out += toupper(name[name.find(' ') + 1]);
  
  return out;
}
