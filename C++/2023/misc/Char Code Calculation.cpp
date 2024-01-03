/*
 * Given a string, turn each character into its ASCII character code and join them together to create a number - let's call this number total1:
 * 
 * 'ABC' --> 'A' = 65, 'B' = 66, 'C' = 67 --> 656667
 * Then replace any incidence of the number 7 with the number 1, and call this number 'total2':
 * 
 * total1 = 656667
 *               ^
 * total2 = 656661
 *              ^
 * Then return the difference between the sum of the digits in total1 and total2:
 * 
 *   (6 + 5 + 6 + 6 + 6 + 7)
 * - (6 + 5 + 6 + 6 + 6 + 1)
 * -------------------------
 *                        6
 */
#include <string>

int calc(const std::string& x) {
  std::string temp1 = "", temp2 = "";
  int total1 = 0, total2 = 0;
  
  for (auto ch : x)
    temp1 += std::to_string(ch - 0);
  
  temp2 = temp1;
  std::replace(temp2.begin(), temp2.end(), '7', '1');
  
  for (auto ch : temp1)
    total1 += ch - '0';
  
  for (auto ch : temp2)
    total2 += ch - '0';
  
  return total1 - total2;
}

// ALTERNATIVE
#include <string>

int calc(const std::string& x) {
  int res = 0;
  
  for (char ch : x) {
    if (ch % 10 == 7) res += 6;
    if (ch / 10 == 7) res +=6 ;
  }
  
  return res;
}
