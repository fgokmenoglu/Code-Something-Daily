#include <string>
#include <algorithm>

// * Task: Write a function which converts
// * the input string to uppercase.
std::string makeUpperCase(const std::string& input_str) {
    std::string result = input_str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
