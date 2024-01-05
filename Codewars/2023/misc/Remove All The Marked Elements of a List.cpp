/*
 * Define a method/function that removes from a given array of integers all the values contained in a second array.
 * 
 * Examples (input -> output):
 * [1, 1, 2, 3, 1, 2, 3, 4], [1, 3] -> [2, 2, 4]
 * [1, 1, 2, 3, 1, 2, 3, 4, 4, 3, 5, 6, 7, 2, 8], [1, 3, 4, 2] -> [5, 6, 7, 8]
 * [8, 2, 7, 2, 3, 4, 6, 5, 4, 4, 1, 2, 3], [2, 4, 3] -> [8, 7, 6, 5, 1]
 */
#include <vector>
#include <algorithm> // find()

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values) {
  std::vector<int> output(integers.begin(), integers.end());
  
  for (int integer : integers) {
    auto it = std::find(values.begin(), values.end(), integer);
  
    if (it != values.end())
      output.erase(std::find(output.begin(), output.end(), integer));
  }
    
  return output;
}

// ALTERNATIVE
#include <vector>
#include <algorithm> // remove()

std::vector<int> remove_values(std::vector<int> integers, std::vector<int> values) {
  for(int i : values) 
    integers.erase(std::remove(integers.begin(), integers.end(), i), integers.end());
  
  return integers;
}
