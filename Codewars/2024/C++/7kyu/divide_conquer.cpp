#include <vector>
#include <variant>

/* Description:
 * Given a mixed array of number and string representations of integers,
 * add up the non-string integers and subtract the total of the string integers.
 */

int divCon(const std::vector<std::variant<int, char>>& x) {
    int result = 0;
    
    for (const auto& element : x) {
        if (std::holds_alternative<int>(element)) {
            // If the element is an int, add it to the result
            result += std::get<int>(element);
        } else {
            // If the element is a char, convert it to int and subtract
            result -= (std::get<char>(element) - '0');
        }
    }
    
    return result;
}
