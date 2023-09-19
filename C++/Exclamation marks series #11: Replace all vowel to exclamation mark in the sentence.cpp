/*
 * Description:
 * Replace all vowel to exclamation mark in the sentence. aeiouAEIOU is vowel.
 * 
 * Examples
 * replace("Hi!") === "H!!"
 * replace("!Hi! Hi!") === "!H!! H!!"
 * replace("aeiou") === "!!!!!"
 * replace("ABCDE") === "!BCD!"
 */
#include <string>

using namespace std;

string replace(const string &s)
{
  string vowels = "aeiouAEIOU";
  string result = s;

  while (result.find_first_of(vowels) != string::npos)
    result[result.find_first_of(vowels)] = '!'; 
  
  return result;
}

// ALTERNATIVE USING REGEX
#include <string>
#include <regex>

using namespace std;

string replace(const string &s)
{
  return regex_replace(s, regex("[aeiouAEIOU]"), "!");
}
