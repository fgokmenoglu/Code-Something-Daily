/*
 * You are given two strings. 
 * In a single move, you can choose any of them, and delete the first (i.e. leftmost) character.
 *
 * For Example:
 * By applying a move to the string "where", the result is the string "here".
 * By applying a move to the string "a", the result is an empty string "".
 * Implement a function that calculates the minimum number of moves that should be performed to make the given strings equal.
 *
 * Notes
 * Both strings consist of lowercase latin letters.
 * If the string is already empty, you cannot perform any more delete operations.
 */
#include <string>

long long shiftLeft(std::string s, std::string t) {
    // Find the lengths of the input strings
    int s_len = s.length();
    int t_len = t.length();
    
    // Initialize the length of the common suffix
    int common_suffix_length = 0;
    
    // Compare from the end of both strings
    while (s_len - common_suffix_length > 0 && t_len - common_suffix_length > 0 && 
           s[s_len - 1 - common_suffix_length] == t[t_len - 1 - common_suffix_length]) {
        ++common_suffix_length;
    }
    
    // The minimum number of moves needed is the total length of both strings
    // minus twice the length of the common suffix
    return (s_len + t_len - 2 * common_suffix_length);
}
