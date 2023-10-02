/*
 * Scenario
 * Several people are standing in a row divided into two teams.
 * The first person goes into team 1, the second goes into team 2, the third goes into team 1, and so on.
 * 
 * Task
 * Given an array of positive integers (the weights of the people), return a new array/tuple of two integers, where the first one is the total weight of team 1, and the second one is the total weight of team 2.
 * 
 * Notes
 * Array size is at least 1.
 * All numbers will be positive.
 *
 * Input >> Output Examples
 *
 * rowWeights([13, 27, 49])  ==>  return (62, 27) 
 * Explanation:
 * The first element 62 is the total weight of team 1, and the second element 27 is the total weight of team 2.
 * 
 * rowWeights([50, 60, 70, 80])  ==>  return (120, 140)
 * Explanation:
 * The first element 120 is the total weight of team 1, and the second element 140 is the total weight of team 2.
 * 
 * rowWeights([80])  ==>  return (80, 0)
 * Explanation:
 * The first element 80 is the total weight of team 1, and the second element 0 is the total weight of team 2.
 */
#include <vector>
#include <utility>

using namespace std; 

pair<int,int> rowWeights (const vector <int> &weights) {
  int sum1 = 0, sum2 = 0;
  
  for (auto i = 0; i < weights.size(); i++)
    if (i % 2 == 0)
      sum1 += weights[i];
    else
      sum2 += weights[i];
  
  return {sum1, sum2};
}

// ALTERNATIVE
#include <vector>
#include <utility>

std::pair<int,int> rowWeights (const std::vector <int> &weights) {
  int sums[2]{ 0, 0 };
  
  for (size_t i = 0; i < weights.size(); i++)
    sums[i % 2] += weights[i];
  
  return std::make_pair(sums[0], sums[1]);
}
