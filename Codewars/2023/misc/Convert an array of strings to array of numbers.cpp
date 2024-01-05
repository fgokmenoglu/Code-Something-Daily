/*
 * Some really funny web dev gave you a sequence of numbers from his API response as an sequence of strings!
 * 
 * You need to cast the whole array to the correct type.
 * 
 * Create the function that takes as a parameter a sequence of numbers represented as strings and outputs a sequence of numbers.
 * 
 * ie:["1", "2", "3"] to [1, 2, 3]
 * 
 * Note that you can receive floats as well.
 */
#include <vector>
#include <string>

std::vector<float> to_float_array(const std::vector<std::string>& arr) {
  std::vector<float> output = {};
  
  for (size_t i = 0; i < arr.size(); i++)
    output.push_back(stof(arr[i]));
  
  return output;
}

// ALTERNATIVE 1
#include <vector>
#include <string>

std::vector<float> to_float_array(const std::vector<std::string>& arr) {
  std::vector<float> ans;
  
  for(auto s : arr)
    ans.push_back(stof(s));
  
  return ans;
}

// ALTERNATIVE 2
#include <vector>
#include <string>
#include <algorithm>

std::vector<float> to_float_array(const std::vector<std::string>& arr) 
{
  std::vector<float> numbers(arr.size());
  std::transform(arr.cbegin(), arr.cend(), numbers.begin(), [](const auto& s) { return std::stof(s); });
  
  return numbers;
}
