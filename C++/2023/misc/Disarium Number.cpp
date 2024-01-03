/*
 * Definition
 * Disarium number is the number that the sum of its digits powered with their respective positions is equal to the number itself.
 * 
 * Task
 * Given a number, Find if it is Disarium or not.
 * 
 * Notes
 * Number passed is always positive.
 * Return the result as string.
 */
#include <string>
#include <cmath>

using namespace std; 

string disariumNumber(int number) {
  string num = to_string(number);
  int sum = 0;
  
  for(size_t i = 1; i <= num.length(); ++i)
    sum += pow((num[i - 1] - '0'), i);
  
  return number == sum ? "Disarium !!" : "Not !!";
}
