/*
 * You are given a list of unique integers arr, and two integers a and b. 
 * Your task is to find out whether or not a and b appear consecutively in arr, and return a boolean value (True if a and b are consecutive, False otherwise).
 *
 * It is guaranteed that a and b are both present in arr, no need for checking against arr.end()
 */
#include <vector>
#include <algorithm> // find()
#include <cstdlib> // abs()

bool consecutive(std::vector<int>arr, int a,int b) {
  auto it1 = find(arr.begin(), arr.end(), a);
  auto it2 = find(arr.begin(), arr.end(), b);
  
  int index1 = it1 - arr.begin();
  int index2 = it2 - arr.begin();
  
  return abs(index1 - index2) == 1 ? true : false;
}

// ALTERNATIVE
#include <vector>
#include <algorithm> // find()
#include <cstdlib> // abs()

bool consecutive(std::vector<int> arr, int a, int b) {
    return abs(find(arr.begin(), arr.end(), a) - find(arr.begin(), arr.end(), b)) == 1;
}
