/*
 * Your task is to combine two Strings considering the following rule:
 * Having two input strings a and b, for every character in string a swap the casing of every occurrence of the same character in string b. 
 * Then do the same casing swap with the inputs reversed. Return a single string consisting of the changed version of a followed by the changed version of b. 
 * A char of a is in b regardless if it's in upper or lower case.
 *
 * Examples:
 * Input: "abc" and "cde"      => Output: "abCCde" 
 * Input: "ab" and "aba"       => Output: "aBABA"
 * Input: "abab" and "bababa"  => Output: "ABABbababa"
 *
 * For the last example, 
 *   i) swap the case of characters in string b for every occurrence of that character in string a
 *   char 'a' occurs twice in string a, so we swap all 'a' in string b twice. This means we start with "bababa" then "bAbAbA" => "bababa"
 *   char 'b' occurs twice in string a and so string b moves as follows: start with "bababa" then "BaBaBa" => "bababa"
 *
 *   ii) then, swap the case of characters in string a for every occurrence in string b
 *   char 'a' occurs 3 times in string b. So string a swaps cases as follows: start with "abab" then => "AbAb" => "abab" => "AbAb"
 *   char 'b' occurs 3 times in string b. So string a swaps as follow: start with "AbAb" then => "ABAB" => "AbAb" => "ABAB".
 *
 *   iii) merge new strings a and b
 *   return "ABABbababa"
 */
#include <string>
#include <unordered_map>

// Helper function to toggle the case of a single character
char toggleCase(char c) {
    if (std::islower(c)) return std::toupper(c);
    return std::tolower(c);
}

// Main function to process strings as described
std::string work_on_strings(const std::string &a, const std::string &b) {
    std::string mod_a = a, mod_b = b;
    
    // Swap cases in b based on characters in a
    std::unordered_map<char, int> freq;
    for (char ch : a) {
        freq[std::tolower(ch)]++;
    }

    for (int i = 0; i < mod_b.size(); ++i) {
        char lower_char = std::tolower(mod_b[i]);
        if (freq[lower_char] % 2 != 0) {
            mod_b[i] = toggleCase(mod_b[i]);
        }
    }

    // Clear the frequency map for reuse
    freq.clear();

    // Swap cases in a based on characters in b
    for (char ch : b) {
        freq[std::tolower(ch)]++;
    }

    for (int i = 0; i < mod_a.size(); ++i) {
        char lower_char = std::tolower(mod_a[i]);
        if (freq[lower_char] % 2 != 0) {
            mod_a[i] = toggleCase(mod_a[i]);
        }
    }

    // Concatenate the modified a and b
    return mod_a + mod_b;
}
