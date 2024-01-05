/*
 * Complete the method which accepts an array of integers, and returns one of the following:
 * 
 * "yes, ascending" - if the numbers in the array are sorted in an ascending order
 * "yes, descending" - if the numbers in the array are sorted in a descending order
 * "no" - otherwise
 * You can assume the array will always be valid, and there will always be one correct answer.
 */
#include <string>
#include <vector>
std::string is_sorted_and_how(std::vector<int> array)
{
  bool ascending = true, descending = true;
  
  for (size_t i = 0; i < array.size() - 1; i++)
    if (array[i] > array[i + 1])
      ascending = false;
    else if (array[i] < array [i + 1])
      descending = false;      
    
  return ascending ? "yes, ascending" : (descending ? "yes, descending" : "no");
}

// ALTERNATIVE
#include <string>
#include <vector>
#include <algorithm>

std::string is_sorted_and_how(const std::vector<int>& a)
{
    return std::is_sorted(std::begin(a), std::end(a)) ? "yes, ascending" :
           std::is_sorted(std::rbegin(a), std::rend(a)) ? "yes, descending" :
           "no";
}
