#include <string>
#include <set>
#include <algorithm>

/* Task:
 * Take 2 strings s1 and s2 including only letters from a to z.
 * Return a new sorted string (alphabetical ascending), the longest possible,
 * containing distinct letters - each taken only once - coming from s1 or s2.
 *
 * Examples:
 * a = "xyaabbbccccdefww"
 * b = "xxxxyyyyabklmopq"
 * longest(a, b) -> "abcdefklmopqwxy"
 *
 * a = "abcdefghijklmnopqrstuvwxyz"
 * longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"
 */

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2)
    {
        // Combine both strings
        std::string combined = s1 + s2;
        
        // Use a set to store unique characters
        std::set<char> unique_chars(combined.begin(), combined.end());
        
        // Convert set back to string
        std::string result(unique_chars.begin(), unique_chars.end());
        
        // Sort the result string
        std::sort(result.begin(), result.end());
        
        return result;
    }
};
