/*
 * Task
 * Given an array/list [] of n integers , find maximum triplet sum in the array Without duplications .
 * 
 * Notes :
 * Array/list size is at least 3.
 * Array/list numbers could be a mixture of positives , negatives and zeros .
 * Repetition of numbers in the array/list could occur.
 * Duplications are not included when summing , (i.e) the numbers added only once.
 * 
 * Input >> Output Examples
 * 1- maxTriSum ({3,2,6,8,2,3}) ==> return (17)
 * Explanation: As the triplet that maximize the sum {6,8,3} in order , their sum is 17.
 */
#include <vector>
#include <algorithm>
#include <functional>

using namespace std; 

int maxTriSum (vector <int> numbers) { 
  sort(numbers.begin(), numbers.end(), greater<int>());
  numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
  
  return numbers[0] + numbers[1] + numbers[2];
}

// ALTERNATIVE
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std; 

int maxTriSum (vector <int> numbers) {
  set<int> uniqueNumbers;
  
  for(size_t i = 0; i < numbers.size(); ++i) 
    uniqueNumbers.insert(numbers[i]);
  
  numbers.assign(uniqueNumbers.begin(), uniqueNumbers.end());
  sort(numbers.begin(), numbers.end(), greater<int>());
  
  return numbers[0] + numbers[1] + numbers[2];
}
