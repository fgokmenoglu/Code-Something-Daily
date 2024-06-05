/*
 * It started as a discussion with a friend, who didn't fully grasp some way of setting defaults, 
 * but I thought the idea was cool enough for a beginner kata: binary OR each matching element of two given arrays 
 * (or lists, if you do it in Python; vectors in c++) of integers and 
 * give the resulting ORed array [starts to sound like a tonguetwister, doesn't it?].
 *
 * If one array is shorter than the other, use the optional third parameter (defaulted to 0) to OR the unmatched elements.
 *
 * For example:
 *
 * orArrays([1,2,3],[1,2,3]) == [1,2,3]
 * orArrays([1,2,3],[4,5,6]) == [5,7,7]
 * orArrays([1,2,3],[1,2]) == [1,2,3]
 * orArrays([1,2],[1,2,3]) == [1,2,3]
 * orArrays([1,2,3],[1,2,3],3) == [1,2,3]
 */
#include <vector>
#include <algorithm>  // for std::max

std::vector<int> orArrays(const std::vector<int>& arr1, const std::vector<int>& arr2, int defaultValue = 0) {
    // Determine the length of the longer array
    size_t maxLength = std::max(arr1.size(), arr2.size());
    
    // Create a result vector of the same length
    std::vector<int> result(maxLength);
    
    // Perform the binary OR operation
    for (size_t i = 0; i < maxLength; ++i) {
        int val1 = (i < arr1.size()) ? arr1[i] : defaultValue;
        int val2 = (i < arr2.size()) ? arr2[i] : defaultValue;
        result[i] = val1 | val2;
    }
    
    return result;
}
