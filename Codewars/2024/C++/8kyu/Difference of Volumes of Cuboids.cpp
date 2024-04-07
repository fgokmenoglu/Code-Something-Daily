/*
 * In this simple exercise, you will create a program that will take two lists of integers, a and b. 
 * Each list will consist of 3 positive integers above 0, representing the dimensions of cuboids a and b. 
 * You must find the difference of the cuboids' volumes regardless of which is bigger.
 * For example, if the parameters passed are ([2, 2, 3], [5, 4, 1]), the volume of a is 12 and the volume of b is 20. Therefore, the function should return 8.
 */
#include <array>
#include <numeric>
#include <functional>

int findDifference(std::array<int, 3> a, std::array<int, 3> b) {
  int volume_a = std::accumulate(a.begin(), a.end(), 1, std::multiplies<int>());
  int volume_b = std::accumulate(b.begin(), b.end(), 1, std::multiplies<int>());
  
  return volume_a > volume_b ? volume_a - volume_b :  volume_b - volume_a;
}

// ALTERNATIVE
#include <array>
#include <cmath>

int findDifference(std::array<int, 3> a, std::array<int, 3> b) {
  return std::abs(a[0] * a[1] * a[2] - b[0] * b[1] * b[2]);
}
