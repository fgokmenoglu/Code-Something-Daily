/*
 * Task:
 * You have to write a function pattern which creates the following pattern upto n number of rows. 
 * If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.
 *
 * Example:
 * pattern(4):
 * 1234
 * 234
 * 34
 * 4
 * 
 * Note: 
 * There are no blank spaces
 */
#include <string>

std::string pattern(int n) {
    if (n <= 0) {
        return "";
    }
    
    std::string pattern;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            pattern += std::to_string(j);
        }
        if (i < n) {
            pattern += "\n";
        }
    }
    
    return pattern;
}
