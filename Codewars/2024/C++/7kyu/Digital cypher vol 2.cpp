/*
 * Introduction
 * Digital Cypher assigns to each letter of the alphabet unique number. For example:
 * 
 *  a  b  c  d  e  f  g  h  i  j  k  l  m
 *  1  2  3  4  5  6  7  8  9 10 11 12 13
 *  n  o  p  q  r  s  t  u  v  w  x  y  z
 * 14 15 16 17 18 19 20 21 22 23 24 25 26
 * Instead of letters in encrypted word we write the corresponding number, eg. The word scout:
 * 
 *  s  c  o  u  t
 * 19  3 15 21 20
 * Then we add to each obtained digit consecutive digits from the key. For example. In case of key equal to 1939 :
 * 
 *    s  c  o  u  t
 *   19  3 15 21 20
 *  + 1  9  3  9  1
 *  ---------------
 *   20 12 18 30 21
 *
 * Task
 * Write a function that accepts an array of integers code and a key number. As the result, it should return string containg a decoded message from the code.
 * 
 * Input / Output
 * The code is a array of positive integers.
 * The key input is a nonnegative integer.
 * 
 * Example
 * decode([ 20, 12, 18, 30, 21],1939);  ==> "scout"
 * decode([ 14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8],1939);  ==>  "masterpiece"
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Kata {
  public:
    static string Decode(vector<int> code, int n) {
      string encoding = " abcdefghijklmnopqrstuvwxyz";
      string output = "";     
      vector<int> digits;
      size_t count = 0;
    
      while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
        count += 1;
      }
      
      reverse(digits.begin(), digits.end());
    
      for (size_t i = 0, j = 0; i < code.size(); ++i) {
        code[i] -= digits[j];
        output.push_back(encoding[code[i]]);
      
        if (j + 1 == count)
          j = 0;
        else
          ++j;
      }
    
      return output;
    }
};

// ALTERNATIVE
using namespace std;

class Kata {
  public:
    static string Decode(vector<int> code, int n) {     
      std::string key = std::to_string(n);
      std::string result; 
      result.resize(code.size());

      for (auto i = 0; i < code.size(); ++i)
        result[i] = 'a' + code[i] - key[i % key.size()] - 1 + '0';
        
      return result;
    }
};
