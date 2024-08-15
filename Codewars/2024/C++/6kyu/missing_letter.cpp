#include <vector>

/* Task Description:
* Write a method that takes an array of consecutive (increasing) letters as input
* and that returns the missing letter in the array.
*
* You will always get an valid array. And it will be always exactly one letter be missing.
* The length of the array will always be at least 2.
* The array will always contain letters in only one case.
* Use the English alphabet with 26 letters!
*
* Example:
* ['a','b','c','d','f'] -> 'e'
* ['O','Q','R','S'] -> 'P'
*/

char findMissingLetter(const std::vector<char>& chars) {
    for (size_t i = 1; i < chars.size(); ++i) {
        if (chars[i] - chars[i-1] > 1) {
            return chars[i-1] + 1;
        }
    }
}
