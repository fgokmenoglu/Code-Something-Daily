/*
 * Definition
 * Jumping number is the number that All adjacent digits in it differ by 1.
 * 
 * Task
 * Given a number, Find if it is Jumping or not .
 * 
 * Notes
 * Number passed is always Positive .
 * Return the result as String .
 * The difference between ‘9’ and ‘0’ is not considered as 1 .
 * All single digit numbers are considered as Jumping numbers.
 */
#include <string>
#include <cstdlib>

using namespace std; 

string jumpingNumber(int number) {
  string numStr = to_string(number);
  
  if(numStr.length() == 1)
    return "Jumping!!";
  
  for(size_t i = 0; i < numStr.length() - 1; ++i)
    if (abs((numStr[i + 1] - '0') - (numStr[i] - '0')) != 1)
      return "Not!!";
  
  return "Jumping!!";
}

// ALTERNATIVE
#include <string>

using namespace std; 

string jumpingNumber(int number) {
  if (number < 10) return "Jumping!!";
  int diff = number % 10 - number / 10 % 10;
  return diff == 1 || diff == -1 ? jumpingNumber(number / 10) : "Not!!";
}

// ALTERNATIVE 2
#include <string>

using namespace std; 

string jumpingNumber (int number) {
  string s = to_string(number);
  
  for (size_t i = 1; i < s.size(); ++i)
    if (abs(s[i] - s[i - 1]) != 1)
      return "Not!!";
  
  return "Jumping!!";
}
