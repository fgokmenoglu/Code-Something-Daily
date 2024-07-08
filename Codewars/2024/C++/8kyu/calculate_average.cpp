/*
 * Write a function which calculates the average of the numbers in a given list.
 * Note: Empty arrays should return 0.
 */
#include <vector>
#include <numeric>

double calcAverage(const std::vector<int>& values){
  return std::accumulate(values.cbegin(), values.cend(), 0.0) / values.size();
}
