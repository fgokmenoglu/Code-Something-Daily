/*
 * You will be given two strings a and b consisting of lower case letters, 
 * but a will have at most one asterix character. 
 * The asterix (if any) can be replaced with an arbitrary sequence (possibly empty) of lowercase letters. 
 * No other character of string a can be replaced. 
 * If it is possible to replace the asterix in a to obtain string b, then string b matches the pattern.
 * If the string matches, return true else false.
 * 
 * For example:
 * solve("code*s","codewars") = true, because we can replace the asterix(*) with "war" to match the second string. 
 * solve("codewar*s","codewars") = true, because we can replace the asterix(*) with "" to match the second string. 
 * solve("codewars","codewars") = true, because the strings already match.
 * solve("a","b") = false
 * solve("*", "codewars") = true
 */
#include <string>

bool solve(std::string a, std::string b) {
    size_t pos = a.find('*');
    if (pos == std::string::npos) {
        // No asterisk found, directly compare the strings
        return a == b;
    } else {
        // Asterisk found, split a into two parts
        std::string prefix = a.substr(0, pos);
        std::string suffix = a.substr(pos + 1);
        
        // Check if b starts with prefix and ends with suffix
        if (b.size() < prefix.size() + suffix.size()) {
            return false;
        }
        
        return b.substr(0, prefix.size()) == prefix && b.substr(b.size() - suffix.size()) == suffix;
    }
}
