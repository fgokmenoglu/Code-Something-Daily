/*
Task

Given an array of integers , Find the minimum sum which is obtained from summing each Two integers product .

Notes

Array/list will contain positives only .
Array/list will always have even size
Input >> Output Examples

minSum({5,4,2,3}) ==> return (22) 
Explanation:

The minimum sum obtained from summing each two integers product ,  5*2 + 3*4 = 22
minSum({12,6,10,26,3,24}) ==> return (342)

 */
#include <vector>

using namespace std;

int minSum (vector<int>passed)
{
  int result = 0;
  
  while(!passed.empty()) {
    int minValue = *std::min_element(passed.begin(), passed.end());
    int maxValue = *std::max_element(passed.begin(), passed.end());

    result += minValue * maxValue;
    
    passed.erase(std::find(passed.begin(), passed.end(), minValue));
    passed.erase(std::find(passed.begin(), passed.end(), maxValue));
  }
  
  return result; 
}

// ALTERNATIVE
#include <vector>
using namespace std;

int minSum (vector<int>passed)
{
  std::sort (passed.begin(), passed.end()); 
  int sum = 0;
  for (int i =0 ; i< passed.size() / 2;i++)
  {    
    sum += passed[i] * passed[passed.size() - i - 1];
  }
  return sum; 
}
