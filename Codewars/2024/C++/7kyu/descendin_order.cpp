#include <cinttypes>
#include <string>
#include <algorithm>

/* Task Description:
* Your task is to make a function that can take any non-negative integer as an argument
* and return it with its digits in descending order. Essentially, rearrange the digits
* to create the highest possible number.
*
* Examples:
* Input: 42145 Output: 54421
* Input: 145263 Output: 654321
* Input: 123456789 Output: 987654321
*/
uint64_t descendingOrder(uint64_t a) {
    // Convert the number to a string
    std::string numStr = std::to_string(a);
    
    // Sort the string in descending order
    std::sort(numStr.begin(), numStr.end(), std::greater<char>());
    
    // Convert the sorted string back to uint64_t
    return std::stoull(numStr);
}
