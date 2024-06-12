/*
 * Change every letter in a given string to the next letter in the alphabet. 
 * The function takes a single parameter s (string).
 *
 * Notes:
 * Spaces and special characters should remain the same.
 * Capital letters should transfer in the same way but remain capitilized.
 * 
 * Examples
 * "Hello"               -->  "Ifmmp"
 * "What is your name?"  -->  "Xibu jt zpvs obnf?"
 * "zoo"                 -->  "app"
 * "zzZAaa"              -->  "aaABbb"
 */
#include <string>

std::string nextLetter(std::string str) {
    for (char &ch : str) {
        if ((ch >= 'a' && ch <= 'y') || (ch >= 'A' && ch <= 'Y')) {
            ch += 1;
        } else if (ch == 'z') {
            ch = 'a';
        } else if (ch == 'Z') {
            ch = 'A';
        }
        // Special characters and spaces are left unchanged
    }
    return str;
}

// ALTERNATIVE
#include <string>
#include <cctype>

std::string nextLetter(std::string str) {
    for (char &c : str) {
        if (std::isalpha(c)) {
            c++;
            if (c == 91 || c == 123) c -= 26;
            // 91 is char after 'Z', 123 is char after 'z'
        }
    }
    return str;
}
