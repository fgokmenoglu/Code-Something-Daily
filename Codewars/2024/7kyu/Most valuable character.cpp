/*
 * In this Kata, you will be given a string and your task is to return the most valuable character. 
 * The value of a character is the difference between the index of its last occurrence and the index of its first occurrence. 
 * Return the character that has the highest value. 
 * If there is a tie, return the alphabetically lowest character. [For Golang return rune]
 * All inputs will be lower case.
 * 
 * For example:
 * solve('a') = 'a'
 * solve('ab') = 'a'. Last occurrence is equal to first occurrence of each character. Return lexicographically lowest.
 * solve("axyzxyz") = 'x'
 */
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

char solve(const string& s) {
  // Map to store the first and last index of each character.
  unordered_map<char, pair<int, int>> indices;

  // Initialize the output character to the max value and max value to 0.
  char out = numeric_limits<char>::max();
  int maxValue = 0;

  // Loop through the string to populate the indices map.
  for (int i = 0; i < s.size(); ++i) {
    if (indices.find(s[i]) == indices.end()) {
      // If it's the first occurrence, store the index.
      indices[s[i]] = make_pair(i, i);
    } else {
      // Update the last index of the character.
      indices[s[i]].second = i;
    }
  }

  // Iterate over the map to find the most valuable character.
  for (const auto& kv : indices) {
    char ch = kv.first;
    int firstIndex = kv.second.first;
    int lastIndex = kv.second.second;
    int value = lastIndex - firstIndex;

    // Check if this character has a higher value, or if it's a tie, whether it's lexicographically smaller.
    if (value > maxValue || (value == maxValue && ch < out)) {
      maxValue = value;
      out = ch;
    }
  }

  return out;
}
