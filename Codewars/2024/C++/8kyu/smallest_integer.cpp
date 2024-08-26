#include <vector>
#include <algorithm>

/* Task Description:
 * Given an array of integers your solution should find the smallest integer.
 *
 * Examples:
 * Given [34, 15, 88, 2] your solution will return 2
 * Given [34, -345, -1, 100] your solution will return -345
 *
 * Notes:
 * You can assume, for the purpose of this kata, that the supplied array will not be empty.
 */

int findSmallest(std::vector<int> list) {
    return *std::min_element(list.begin(), list.end());
}
