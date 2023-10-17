/*
 * Write function max_rot(n) which given a positive integer n returns the maximum number you got doing rotations similar to the above example.
 * 
 * So max_rot (or maxRot or ... depending on the language) is such as:
 * 
 * max_rot(56789) should return 68957
 * 
 * max_rot(38458215) should return 85821534
 */
#include <string>

class MaxRotate {
  private:
    // Helper function to rotate a string to the left
    static std::string rotateLeft(const std::string& str) {
      return str.substr(1) + str[0];
    }
  
  public: 
    static long long maxRot(long long n) {
      std::string numStr = std::to_string(n);
      std::string maxNumStr = numStr;
      unsigned long long maxNum = n;

      for (size_t i = 0; i < numStr.length() - 1; ++i) {
        numStr = numStr.substr(0, i) + rotateLeft(numStr.substr(i));
        unsigned long long rotatedNum = std::stoull(numStr);
        
        if (rotatedNum > maxNum) {
          maxNum = rotatedNum;
          maxNumStr = numStr;
        }
      }
      
      return maxNum;
    }
};

// ALTERNATIVE
#include <algorithm>
#include <string>

class MaxRotate {
  public:
    static long long maxRot(long long n);
};

long long MaxRotate::maxRot(long long n) {
  std::string s = std::to_string(n);
  
  for (int i = 0; i < s.length() - 1; ++i) {
    std::rotate(s.begin() + i, s.begin() + i + 1, s.end());
    n = std::max(stoll(s), n);
  }
  
  return n;
}
