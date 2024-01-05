/*
 * The vowel substrings in the word codewarriors are o,e,a,io. The longest of these has a length of 2. 
 * Given a lowercase string that has alphabetic characters only (both vowels and consonants) and no spaces, return the length of the longest vowel substring. 
 * Vowels are any of aeiou.
 */
#include <string>

using namespace std;

int solve(string s) {
	string vowels = "aeiou";
  int longest = 0, current = 0;
  bool found = false;
  
  for (auto ch : s)
    if (vowels.find(ch) != std::string::npos) {
      found = true;
      current += 1;
    }
    else if (found) {
      if (current > longest)
        longest = current;
      
      current = 0;
      found = false;
    }
  
  if (current != 0)
    if (current > longest)
      longest = current;
      
  return longest;
}

// ALTERNATIVE
#include <string>
#include <algorithm>

using namespace std;

int solve(string s) {
  int count = 0;
  int best = 0;
  
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') 
       count++;
    else
      count = 0;
   
    best = max(best, count);
  }
  
  return best;
}
