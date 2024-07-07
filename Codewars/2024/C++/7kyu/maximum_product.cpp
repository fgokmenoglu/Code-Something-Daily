/*
 * In this Kata, you will be given a multi-dimensional array containing 2 or more sub-arrays of integers. 
 * Your task is to find the maximum product that can be formed by taking any one element from each sub-array.
 * 
 * Examples:
 * solve( [[1, 2],[3, 4]] ) = 8. The max product is given by 2 * 4
 * solve( [[10,-15],[-1,-3]] ) = 45, given by (-15) * (-3)
 * solve( [[1,-1],[2,3],[10,-100]] ) = 300, given by (-1) * 3 * (-100)
 */
#include <vector>
#include <algorithm>

int solve(std::vector<std::vector<int>> v) {
    int n = v.size();
    std::vector<long long> max_product(1, 1);
    std::vector<long long> min_product(1, 1);

    for (const auto& subarray : v) {
        std::vector<long long> new_max, new_min;
        for (int num : subarray) {
            for (long long prod : max_product) {
                new_max.push_back(prod * num);
                new_min.push_back(prod * num);
            }
            for (long long prod : min_product) {
                new_max.push_back(prod * num);
                new_min.push_back(prod * num);
            }
        }
        max_product = {*std::max_element(new_max.begin(), new_max.end())};
        min_product = {*std::min_element(new_min.begin(), new_min.end())};
    }

    return static_cast<int>(max_product[0]);
}

// ALTERNATIVE
#include <vector>
#include <algorithm>

int solve(std::vector<std::vector<int>> v) {
  int r_min = 1, r_max = 1;
  for (auto &x : v) {
    int y = *std::min_element(x.begin(), x.end()), z = *std::max_element(x.begin(), x.end());
    int a[4] = {r_min * y, r_min * z, r_max * y, r_max * z};
    r_min = *std::min_element(std::begin(a), std::end(a));
    r_max = *std::max_element(std::begin(a), std::end(a));
  }
  return r_max;
}
