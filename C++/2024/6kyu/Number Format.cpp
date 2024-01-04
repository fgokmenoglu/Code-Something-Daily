/*
 * Format any integer provided into a string with "," (commas) in the correct places.
 * 
 * Example:
 * 
 * For n = 100000 the function should return '100,000';
 * For n = 5678545 the function should return '5,678,545';
 * for n = -420902 the function should return '-420,902'.
 */
#include <string>
#include <algorithm>

std::string numberFormat(long long n) {
  std::string nStr = std::to_string(n), out = "";
  int sepCnt = 0, loopEnd = 0;
  
  // Check if the number is negative and if so add minus to the return value, 
  // also update the negative number flag, i.e. loopEnd
  if (n < 0) {
    out += '-';
    loopEnd = 1;
  }
  
  // Loop through the number string and update the return value
  for (int i = nStr.length() - 1; i >= loopEnd; --i) {
    sepCnt += 1;
    out += nStr[i];
    
    // Check if there is a need for a thousands separator and if so add comma to the return value
    if(sepCnt % 3 == 0)
      out += ',';
  }
  
  // If any, remove the last ',' from the return value
  if (out[out.length() - 1] == ',')
    out.pop_back();
  
  // Reverse the return value so that it is in the correct order
  n > 0 ? reverse(out.begin(), out.end()) : reverse(out.begin() + 1, out.end());
  
  return out;
}

// ALTERNATIVE
#include<string>

std::string numberFormat(long long n) {
	std::string str = std::to_string(n);
  
	for (int i = str.size() - 3; i > 0; i -= 3) {
		if (str.at(i - 1) == '-') 
      break;
    
		str.insert(str.begin() + i, ',');
	}
  
	return str;
}
