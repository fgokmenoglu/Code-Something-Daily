/*
 * Given a 2D ( nested ) list ( array, vector, .. ) of size m * n, your task is to find the sum of the minimum values in each row.
 * 
 * For Example:
 * 
 * [ [ 1, 2, 3, 4, 5 ]        #  minimum value of row is 1
 * , [ 5, 6, 7, 8, 9 ]        #  minimum value of row is 5
 * , [ 20, 21, 34, 56, 100 ]  #  minimum value of row is 20
 * ]
 * So the function should return 26 because the sum of the minimums is 1 + 5 + 20 = 26.
 * 
 * Note: You will always be given a non-empty list containing positive values.
 */
#include <vector>

int sum_of_minimums(const std::vector<std::vector<int>> &numbers)
{
  int rows = numbers.size();
  // int cols = numbers[0].size();

  int result = 0;
  
  for (int i = 0; i < rows; i++)
  {
    result += *(std::min_element(numbers[i].begin(), numbers[i].end()));
  }
  
  return result;
}

// ALTERNATIVE
#include <numeric>

int sum_of_minimums(std::vector<std::vector<int>> &numbers) 
{
    return std::accumulate(numbers.begin(), numbers.end(), 0, [](auto r, auto e){ return r + *std::min_element(e.begin(), e.end()); });
}

// [] is called the lambda introducer which denotes the start of the lambda expression
// () is called the parameter list which is similar to the () operator of a normal function
// By default, lambda functions cannot access variables of the enclosing function. In order to access those variables, we use the capture clause [].
