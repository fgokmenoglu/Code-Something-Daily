#include <string>
#include <sstream>
#include <limits>
#include <algorithm>

/* Task Description:
* In this little assignment you are given a string of space separated numbers,
* and have to return the highest and lowest number.
*
* Examples:
* highAndLow("1 2 3 4 5");  // return "5 1"
* highAndLow("1 2 -3 4 5"); // return "5 -3"
* highAndLow("1 9 3 4 -5"); // return "9 -5"
*
* Notes:
* All numbers are valid Int32, no need to validate them.
* There will always be at least one number in the input string.
* Output string must be two numbers separated by a single space, and highest number is first.
*/
std::string highAndLow(const std::string& numbers) {
    std::istringstream iss(numbers);
    int num, highest = std::numeric_limits<int>::min(), lowest = std::numeric_limits<int>::max();
    
    while (iss >> num) {
        highest = std::max(highest, num);
        lowest = std::min(lowest, num);
    }
    
    return std::to_string(highest) + " " + std::to_string(lowest);
}
