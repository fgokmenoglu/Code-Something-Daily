/*
 * A format for expressing an ordered list of integers is to use a comma separated list of either
 * individual integers or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. 
 * The range includes all integers in the interval including both endpoints. 
 * It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"
 * Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.
 *
 * Example:
 * range_extraction({-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20});
 * returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
 */

#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
    if (args.empty()) return "";

    std::string result;
    int start = args[0], end = args[0];

    for (size_t i = 1; i <= args.size(); ++i) {
        if (i < args.size() && args[i] == end + 1) {
            end = args[i];
        } else {
            if (end - start >= 2) {
                result += std::to_string(start) + "-" + std::to_string(end) + ",";
            } else {
                for (int j = start; j <= end; ++j) {
                    result += std::to_string(j) + ",";
                }
            }
            if (i < args.size()) {
                start = end = args[i];
            }
        }
    }

    // Remove the trailing comma
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}
