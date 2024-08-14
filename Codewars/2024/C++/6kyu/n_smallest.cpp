/*
 * Task Description:
 * Your task is to write a function that does just what the title suggests 
 * (so, fair warning, be aware that you are not getting out of it 
 * just throwing a lame basic sorting method there) 
 * with a list of integers and the expected number n of smallest elements to return.
 *
 * Notes:
 * - the number of elements to be returned cannot be higher than the list length;
 * - elements can be duplicated;
 * - in case of duplicates, just return them according to the original order (see third example for more clarity).
 * 
 * Examples:
 * Array               N    Expected
 * [1, 2, 3, 4, 5]     3    [1, 2, 3]
 * [5, 4, 3, 2, 1]     3    [3, 2, 1]
 * [1, 2, 3, 4, 1]     3    [1, 2, 1]
 * [1, 2, 3, -4, 0]    3    [1, -4, 0]
 * [1, 2, 3, 4, 5]     0    []
 */
#include <vector>
#include <algorithm>
#include <utility>

std::vector<int> firstNSmallest(const std::vector<int>& arr, int n) {
    if (n <= 0 || n > arr.size()) {
        return {};
    }

    std::vector<std::pair<int, size_t>> indexed_arr;
    for (size_t i = 0; i < arr.size(); ++i) {
        indexed_arr.emplace_back(arr[i], i);
    }

    std::partial_sort(indexed_arr.begin(), indexed_arr.begin() + n, indexed_arr.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });

    std::vector<std::pair<int, size_t>> result(indexed_arr.begin(), indexed_arr.begin() + n);

    std::sort(result.begin(), result.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    std::vector<int> final_result;
    for (const auto& pair : result) {
        final_result.push_back(pair.first);
    }

    return final_result;
}
