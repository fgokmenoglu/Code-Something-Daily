/*
 * Complete the function to find the count of the most frequent item of an array. You can assume that input is an array of integers. For an empty array return 0
 * 
 * Example
 * input array: [3, -1, -1, -1, 2, 3, -1, 3, -1, 2, 4, 9, 3]
 * ouptut: 5 
 * The most frequent number in the array is -1 and it occurs 5 times.
 */
#include <vector>
#include <algorithm> // count()

unsigned int most_frequent_item_count(const std::vector<int>& collection) {
  if (collection.empty())
    return 0;
  
  unsigned int countMostFrequent = 0, temp = 0;
  
  for (size_t i = 0; i < collection.size(); i++) {
    temp = std::count(collection.begin(), collection.end(), collection[i]);
  
    if (temp > countMostFrequent)
      countMostFrequent = temp;
  }
  
  return countMostFrequent;
}

// ALTERNATIVE
#include <vector>
#include <unordered_map>
#include <algorithm> // max_element()

unsigned int most_frequent_item_count(const std::vector<int>& collection) {
    if (collection.empty()) return 0;

    std::unordered_map<int, unsigned int> counts;
  
    for (const auto& elem : collection) counts[elem]++;

    return std::max_element(
               std::cbegin(counts), std::cend(counts),
               [](const auto& left, const auto& right) { return left.second < right.second; })
        -> second;
}
