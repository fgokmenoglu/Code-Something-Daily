/*
 * Find the length of the longest substring in the given string s that is the same in reverse.
 * As an example, if the input was “I like racecars that go fast”, the substring (racecar) length would be 7.
 * If the length of the input string is 0, the return value must be 0.
 *
 * Example:
 * "a" -> 1 
 * "aab" -> 2  
 * "abcde" -> 1
 * "zzbaabcd" -> 4
 * "" -> 0
 */
#include <vector>
#include <string>
#include <algorithm>

int longest_palindrome(const std::string &s) {
    int n = s.size();
    if (n == 0) return 0;

    // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

    int maxLength = 1; // Single character is always a palindrome

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // Check for sub-strings of length 2.
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    // k is the length of the substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from starting index i and length k
            int j = i + k - 1;

            // Check if the substring from i to j is a palindrome
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;

                // Update the maximum length
                maxLength = std::max(maxLength, k);
            }
        }
    }

    return maxLength;
}

// ALTERNATIVE
#include <algorithm>

int longest_palindrome(const std::string &s) {
    int maxlen = 0;
  
    for ( int i = 0; i < s.size(); ++i )
      for ( int j = 0; j < s.size(); ++j ) {
        std::string sub = s.substr(i, s.size()-j);
        std::string rev = sub;
        std::reverse ( rev.begin(), rev.end());
      
        if ( sub == rev )
          maxlen = sub.size() > maxlen ? sub.size() : maxlen;
    }
    
    return maxlen;
}
