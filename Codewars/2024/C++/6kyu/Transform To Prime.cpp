/*
 * Task
 * Given a List [] of n integers , find minimum number to be inserted in a list, so that sum of all elements of list should equal the closest prime number.
 * 
 * Notes
 * List size is at least 2 .
 * List's numbers will only positives (n > 0) .
 * Repetition of numbers in the list could occur .
 * The newer list's sum should equal the closest prime number .
 *
 * Input >> Output Examples
 * minimumNumber ({3,1,2}) ==> return (1)
 * Explanation:
 * Since , the sum of the list's elements equal to (6) , the minimum number to be inserted to transform the sum to prime number is (1), 
 * which will make the sum of the List equal the closest prime number (7) .
 */
#include <vector>
#include <numeric>

using namespace std;

bool isPrime (int num) {
  if (num == 1)
    return false;
  
  int i = 2;
  
  while (i * i < num) {
    if (num % i == 0)
      return false;
    
    ++i;
  }
  
  return true;
}

int minimumNumber (vector <int> numbers) {
  auto sum = std::reduce(numbers.begin(), numbers.end());
  auto temp = sum;
  
  while (true) {
    if (isPrime(temp))  
      return temp - sum;
    
    ++temp;
  }
}
