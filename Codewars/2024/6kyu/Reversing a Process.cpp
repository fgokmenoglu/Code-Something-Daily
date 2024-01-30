/*
 * Suppose we know the process by which a string s was encoded to a string r (see explanation below). 
 * The aim of the kata is to decode this string r to get back the original string s.
 * 
 * Explanation of the encoding process:
 * * The inputs are (1) a string composed of lowercase letters from "a" to "z", and (2) a positive integer num.
 * * We know that there is a correspondence between abcde...uvwxyz and 0, 1, 2 ..., 23, 24, 25 : 0 <-> a, 1 <-> b ...
 * * If c is a character of the input string whose corresponding number is x, 
 * * Apply to x the function f: x-> f(x) = num * x % 26, then find ch the corresponding character of f(x),
 * * Accumulate all these ch in a string r, concatenate num and r and return the result.
 *
 * For example: encode("mer", 6015)  -->  "6015ekx"
 *
 * m --> 12,   12 * 6015 % 26 = 4,    4  --> e
 * e --> 4,     4 * 6015 % 26 = 10,   10 --> k
 * r --> 17,   17 * 6015 % 26 = 23,   23 --> x
 *
 * So we get "ekx", hence the output is "6015ekx"
 *
 * Note: Indeed it can happen that the decoding is impossible for strings composed of whatever letters from "a" to "z" 
 * when positive integer num has not been correctly chosen. In that case return "Impossible to decode".
 */
#include <string>
#include <cctype> // for std::isdigit

namespace process {
  int modInverse(int a, int m) {
    // Calculate the modular multiplicative inverse of 'a' modulo 'm'.
    for (int x = 1; x < m; x++) {
      if ((a * x) % m == 1) {
        return x;
      }
    }
    return -1; // No inverse exists if function returns -1.
  }

  std::string decode(const std::string &r) {
    size_t nonDigitPos = 0;

    // Extract the code and the encoded string.
    while (nonDigitPos < r.size() && std::isdigit(r[nonDigitPos]))
      nonDigitPos++;
    
    int code = std::stoi(r.substr(0, nonDigitPos));
    std::string toDecode = r.substr(nonDigitPos);

    int inverse = modInverse(code, 26);
    if (inverse == -1) {
      return "Impossible to decode"; // No inverse, so decoding is impossible.
    }

    std::string out = "";
    for (char encodedChar : toDecode) {
      int originalPos = (inverse * (encodedChar - 'a')) % 26;
      out.push_back('a' + originalPos);
    }
    
    return out;
  }
}
