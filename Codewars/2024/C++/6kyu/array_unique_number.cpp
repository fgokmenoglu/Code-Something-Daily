/*
 * There is an array with some numbers. 
 * All numbers are equal except for one. Try to find it!
 * 
 * Examples
 * find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
 * find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55
 *
 * Notes
 * It’s guaranteed that array contains at least 3 numbers.
 * The tests contain some very huge arrays, so think about performance.
 */
#include <vector>
#include <unordered_set>

float find_uniq(const std::vector<float> &v)
{
    // Use first three elements to determine the unique number
    if (v[0] != v[1]) {
        return (v[0] == v[2]) ? v[1] : v[0];
    }

    float common = v[0];

    // Iterate through the vector to find the unique number
    for (size_t i = 2; i < v.size(); ++i) {
        if (v[i] != common) {
            return v[i];
        }
    }
}
