/*
 * The bloody photocopier is broken... 
 * Just as you were sneaking around the office to print off your favourite binary code!
 * Instead of copying the original, it reverses it: '1' becomes '0' and vice versa.
 * Given a string of binary, return the version the photocopier gives you as a string.
 */
#include <string>

std::string broken(const std::string& inp) {
  std::string out{inp};
  
  for (auto &ch : out)
    if (ch == '1')
      ch = '0';
    else
      ch = '1';
  
  return out;
}
