/*
 * Your task, is to create N×N multiplication table, of size provided in parameter.
 * 
 * For example, when given size is 3:
 * 
 * 1 2 3
 * 2 4 6
 * 3 6 9
 * For the given example, the return value should be:
 * 
 * [[1,2,3],[2,4,6],[3,6,9]]
 */
#include <vector>

using namespace std;

vector<vector<int>> multiplication_table(int n)
{
  vector<vector<int>> result = {};
  vector<int> row = {};
  
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      row.push_back(i * j);  
    }
    
    result.push_back(row);
    row = {};
  }
  
  return result;
}

// ALTERNATIVE
#include <vector>

using namespace std;
vector<vector<int>> multiplication_table(int n) {
  vector<vector<int>> result(n, vector<int>(n));
  for (int i = 0; i < n ; i ++) {
    for (int j = 0; j < n ; j ++) result[i][j] = (i + 1) * (j + 1);
  }
  return result;
}
