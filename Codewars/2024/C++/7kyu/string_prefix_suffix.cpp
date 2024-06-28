/*
 * In this Kata, you will be given a string and your task will be to return 
 * the length of the longest prefix that is also a suffix. 
 * A prefix is the start of a string while the suffix is the end of a string. 
 * For instance, the prefixes of the string "abcd" are ["a","ab","abc"]. 
 * The suffixes are ["bcd", "cd", "d"]. You should not overlap the prefix and suffix.
 *
 * for example:
 * solve("abcd") = 0, because no prefix == suffix. 
 * solve("abcda") = 1, because the longest prefix which == suffix is "a".
 * solve("abcdabc") = 3. Longest prefix which == suffix is "abc".
 * solve("aaaa") = 2. Longest prefix which == suffix is "aa". You should not overlap the prefix and suffix
 * solve("aa") = 1. You should not overlap the prefix and suffix.
 * solve("a") = 0. You should not overlap the prefix and suffix.
 *
 * All strings will be lowercase and string lengths are 1 <= length <= 500
 */
int solve(std::string s) {
    int n = s.length();
    if (n < 2) return 0;  // If string length is 0 or 1, return 0
    
    for (int len = n / 2; len > 0; len--) {
        if (s.substr(0, len) == s.substr(n - len)) {
            return len;
        }
    }
    
    return 0;
}
