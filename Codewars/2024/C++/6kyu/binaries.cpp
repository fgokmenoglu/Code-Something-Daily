/*
 * Let us take a string composed of decimal digits: "10111213". 
 * We want to code this string as a string of 0 and 1 and after that be able to decode it.
 * To code we decompose the given string in its decimal digits (in the above example: 1 0 1 1 1 2 1 3) and we will code each digit.
 * 
 * Coding process to code a number n expressed in base 10:
 * For each digit d of n
 * a) Let k be the number of bits of d
 * b) Write k-1 times the digit 0 followed by the digit 1
 * c) Write digit d as a binary string, with the rightmost bit being the least significant
 * d) Concat the result of b) and c) to get the coding of d
 * At last concatenate all the results got for the digits of n.
 * 
 * An example
 * So we code 0 as 10, 1 as 11, 2 as 0110, 3 as 0111 ... etc...
 * With the given process, the initial string "10111213" becomes: "11101111110110110111" resulting of concatenation of 11 10 11 11 11 0110 11 0111.
 * 
 * Task:
 * Given strng a string of digits representing a decimal number the function code(strng) should return the coding of strng as explained above.
 * Given a string strng resulting from the previous coding, decode it to get the corresponding decimal string.
 * 
 * Examples:
 * code("77338855") --> "001111001111011101110001100000011000001101001101"
 * code("77338")  --> "0011110011110111011100011000"
 * code("0011121314") --> "1010111111011011011111001100"
 * 
 * decode("001111001111011101110001100000011000001101001101") -> "77338855"
 * decode("0011110011110111011100011000") -> "77338"
 * decode("1010111111011011011111001100") -> "0011121314"
 */
#include <string>
#include <cmath>

namespace coding {
    std::string code(const std::string &strng) {
        std::string result;

        for (char c : strng) {
            int d = c - '0';
            int k = d == 0 ? 1 : std::ceil(std::log2(d + 1));
            // Prefix with k-1 zeros and one '1'
            result.append(k - 1, '0');
            result.push_back('1');

            // Binary representation of d
            for (int i = k - 1; i >= 0; --i) {
                result.push_back(((d >> i) & 1) ? '1' : '0');
            }
        }

        return result;
    }

    std::string decode(const std::string &str) {
        std::string result;
        size_t i = 0;

        while (i < str.size()) {
            // Read the prefix to determine k
            int k = 1; // We start with k = 1 because we must count the '1' in the prefix
            while (i < str.size() && str[i] == '0') {
                k++;
                i++;
            }
            // Skip the '1' in the prefix
            i++;

            // Read the next k bits to get the binary representation of the digit
            int d = 0;
            for (int j = 0; j < k; j++) {
                d = (d << 1) | (str[i] - '0');
                i++;
            }
            result.push_back('0' + d);
        }

        return result;
    }
}

