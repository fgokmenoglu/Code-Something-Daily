#include <stdbool.h>

/*
 * Task Description:
 * Given a string, return true if the first instance of "x" in the string
 * is immediately followed by the string "xx".
 *
 * Examples:
 * "abraxxxas" → true
 * "xoxotrololololololoxxx" → false
 * "softX kitty, warm kitty, xxxxx" → true
 * "softx kitty, warm kitty, xxxxx" → false
 *
 * Notes:
 * - Capital X's do not count as an occurrence of "x".
 * - If there are no "x"'s then return false.
 */

bool triple_x(const char *string)
{
    // Iterate through the string
    while (*string != '\0') {
        // Check if the current character is a lowercase 'x'
        if (*string == 'x') {
            // Check if the next two characters are also 'x'
            if (*(string + 1) == 'x' && *(string + 2) == 'x') {
                return true;
            }
            // If we found an 'x' but it's not followed by two more, return false
            return false;
        }
        string++;
    }
    // If we didn't find any 'x', return false
    return false;
}
