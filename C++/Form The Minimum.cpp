/*
 * Task
 * Given a list of digits, return the smallest number that could be formed from these digits, using the digits only once (ignore duplicates).
 * 
 * Notes:
 * Only positive integers will be passed to the function (> 0 ), no negatives or zeros.
 *
 * Input >> Output Examples
 * minValue ({1, 3, 1})  ==> return (13)
 * Explanation:
 * (13) is the minimum number could be formed from {1, 3, 1} , Without duplications
 */
#include <vector>
#include <set>
#include <cmath>

using namespace std; 

unsigned long long minValue (vector <int> values) {
  unsigned long long result = 0;
  set<int> digits(values.begin(), values.end());
  
  auto it = digits.begin();
  
  for(int i = digits.size() - 1; i >= 0; i--) {
    result += (*it) * pow(10, i);
    it++;
  }
  
  return result;
}
