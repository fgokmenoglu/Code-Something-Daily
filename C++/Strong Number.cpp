/*
 * Definition
 * Strong number is the number that the sum of the factorial of its digits is equal to number itself.
 * 
 * For example, 145 is strong, since 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * 
 * Task
 * Given a number, Find if it is Strong or not and return either "STRONG!!!!" or "Not Strong !!".
 * 
 * Notes
 * Number passed is always Positive.
 * Return the result as String
 */
#include <string>

using namespace std;

int factorial(int number) {
  if (number == 1 || number == 0)
    return 1;
  else
    return number * factorial(number - 1);
}

string strong_num(int number) {
  cout << number << endl;
  int temp = number, sum = 0;
  
  while (temp > 0) {
    sum += factorial(temp % 10);
    temp /= 10;
  }
  
  return number == sum ? "STRONG!!!!" : "Not Strong !!"; 
}

// ALTERNATIVE
#include <string>

using namespace std; 

string strong_num(int number) {
    int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int sum = 0;
    int temp = number;
  
    while(temp > 0) {
      sum += fac[temp % 10];
      temp /= 10;
    }
  
    return sum == number ? "STRONG!!!!" : "Not Strong !!"; 
}
