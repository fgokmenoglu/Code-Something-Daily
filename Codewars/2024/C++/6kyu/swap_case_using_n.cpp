/*
 * Your job is to change the given string s using a non-negative integer n.
 * 
 * Each bit in n will specify whether or not to swap the case for each alphabetic character in s: 
 * if the bit is 1, swap the case; if its 0, leave it as is. 
 * When you finish with the last bit of n, start again with the first bit.
 * 
 * You should skip the checking of bits when a non-alphabetic character is encountered, 
 * but they should be preserved in their original positions.
 * 
 * Examples
 * swap("Hello world!", 11)  -->  "heLLO wORLd!"
 * ...because 11 is 1011 in binary, so the 1st, 3rd, 4th, 5th, 7th, 8th and 9th alphabetical characters have to be swapped:
 * 
 * H e l l o   w o r l d !
 * 1 0 1 1 1 x 0 1 1 1 0 x
 * ^   ^ ^ ^    ^ ^ ^
 * 
 * More examples
 * swap("gOOd MOrniNg", 7864)        -->  "GooD MorNIng"
 * swap("", 11345)                   -->  ""
 * swap("the lord of the rings", 0)  -->  "the lord of the rings"
 */
#include <string>
#include <bitset>
#include <iostream>

std::string swap(std::string s, int n) {
    // Convert the integer n to a binary string
    std::string binary = std::bitset<32>(n).to_string();
    
    // Remove leading zeros for easier handling
    size_t firstOne = binary.find('1');
    if (firstOne != std::string::npos) {
        binary = binary.substr(firstOne);
    } else {
        // If there are no '1's, the binary string is effectively "0"
        binary = "0";
    }
    
    int bitIndex = 0;
    int bitLength = binary.length();
    
    for (char& c : s) {
        if (isalpha(c)) {
            // Check if the current bit is 1 to swap the case
            if (binary[bitIndex] == '1') {
                if (islower(c)) {
                    c = toupper(c);
                } else {
                    c = tolower(c);
                }
            }
            // Move to the next bit
            bitIndex = (bitIndex + 1) % bitLength;
        }
    }
    
    return s;
}
