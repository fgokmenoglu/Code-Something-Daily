/*
 * A non-empty array a of length n is called 
 * an array of all possibilities if it contains 
 * all numbers between 0 and a.length - 1 (both inclusive).
 * 
 * Write a function that accepts an integer array and returns true if the array is an array of all possibilities, else false.
 * 
 * Examples:
 * [1,2,0,3] => True
 * # Includes all numbers between 0 and a.length - 1 (4 - 1 = 3)
 * [0,1,2,2,3] => False
 * # Doesn't include all numbers between 0 and a.length - 1 (5 - 1 = 4)
 * [0] => True
 * # Includes all numbers between 0 and a.length - 1 (1 - 1 = 0).
 */
#include <vector>
#include <unordered_set>

bool isAllPossibilities(std::vector<int> arr){
  if (arr.size() == 0)
    return false;
  
  std::unordered_set<int> elements(arr.begin(), arr.end());

  for (size_t i = 0; i < arr.size(); ++i) {
    if (elements.find(i) == elements.end()) {
      return false;
    }
  }

  return true;
}
