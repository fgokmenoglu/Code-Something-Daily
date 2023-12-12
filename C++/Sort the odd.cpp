/*
 * Task
 * You will be given an array of numbers. You have to sort the odd numbers in ascending order while leaving the even numbers at their original positions.
 * 
 * Examples
 * [7, 1]  =>  [1, 7]
 * [5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
 * [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
 */
#include <vector>
#include <algorithm>

class Kata {
  public:
    std::vector<int> sortArray(std::vector<int> array) {
      std::vector<int> output(array.size());
      std::vector<int> odds = {};
      
      for (size_t i = 0; i < array.size(); ++i)
        if (array[i] % 2 == 1) {
          odds.push_back(array[i]);
          output[i] = -1;
        } 
        else
          output[i] = array[i];
      
      std::sort(odds.begin(), odds.end());
      int j = 0;
      
      for (size_t i = 0; i < output.size(); ++i)
        if (output[i] == -1)
          output[i] = odds[j++];
      
      return output;
    }
};

// ALTERNATIVE
#include <vector>
#include <algorithm>

class Kata {
  public:
    std::vector<int> sortArray(std::vector<int> array) {
        std::vector<int> odds;
        std::copy_if(array.begin(), array.end(), std::back_inserter(odds), [] (int x) { return x % 2; });
        std::sort(odds.begin(), odds.end());
        for (int i = 0, j = 0; i < array.size(); i++) if (array[i] % 2) array[i] = odds[j++];
        return array;
    }
};
