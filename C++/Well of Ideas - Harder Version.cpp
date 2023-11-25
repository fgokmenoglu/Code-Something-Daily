/*
 * For every good kata idea there seem to be quite a few bad ones!
 *
 * In this kata you need to check the provided 2 dimensional array (x) for good ideas 'good' and bad ideas 'bad'. If there are one or two good ideas, return 'Publish!', if there are more than 2 return 'I smell a series!'. If there are no good ideas, as is often the case, return 'Fail!'.
 *
 * The sub arrays may not be the same length.
 *
 * The solution should be case insensitive (ie good, GOOD and gOOd all count as a good idea). All inputs may not be strings.
 */
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::string well(const std::vector<std::vector<std::string>>& arr) {
  int goodCount = 0;
  
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[i].size(); j++) {
      std::string temp = arr[i][j];
      std::transform(temp.begin(), temp.end(), temp.begin(),
    [](unsigned char ch){ return std::tolower(ch); });
      
      if (temp == "good")
        goodCount += 1;
    }
  }
  
  if (goodCount == 1 || goodCount == 2)
    return "Publish!";
  else if (goodCount > 2)
    return "I smell a series!";
  else
    return "Fail!";
}

// ALTERNATIVE
