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

std::string swap(std::string s, int n) {
    std::string result = s;
    std::bitset<32> bits(n); // We use bitset to handle binary representation of n
    int bit_length = bits.size();
    int bit_index = 0;
    int alphabetic_index = 0; // to keep track of alphabetic characters only

    for (char &c : result) {
        if (isalpha(c)) {
            if (bits[alphabetic_index % bit_length]) { // Check if the current bit is 1
                if (islower(c)) {
                    c = toupper(c);
                } else if (isupper(c)) {
                    c = tolower(c);
                }
            }
            alphabetic_index++;
        }
    }

    return result;
}
