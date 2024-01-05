/*
 * You are working at a lower league football stadium and you've been tasked with automating the scoreboard.
 * 
 * The referee will shout out the score, you have already set up the voice recognition module which turns the ref's voice into a string, but the spoken score needs to be converted into a pair for the scoreboard!
 * 
 * e.g. "The score is four nil" should return [4,0]
 * 
 * Either teams score has a range of 0-9, and the ref won't say the same string every time e.g.
 * 
 * "new score: two three"
 *   
 * "two two"
 *   
 * "Arsenal just conceded another goal, two nil"
 * Note: Please return a std::vector<int>
 */
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> scoreboard(const std::string &s) {
    std::vector<std::string> scores = {"nil", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::pair<int, size_t>> foundScores; // Pair of score and its position

    // Find scores and their positions
    for (int i = 0; i < 10; ++i) {
        size_t pos = s.find(scores[i]);
        while (pos != std::string::npos) {
            foundScores.push_back({i, pos});
            pos = s.find(scores[i], pos + 1);
        }
    }

    // Sort by position
    std::sort(foundScores.begin(), foundScores.end(), [](const std::pair<int, size_t>& a, const std::pair<int, size_t>& b) {
        return a.second < b.second;
    });

    // Extract the scores in the order they appear
    std::vector<int> result;
    for (auto& score : foundScores) {
        result.push_back(score.first);
    }

    // Handle cases where only one score is found
    if (result.size() == 1) {
        result.push_back(0); // Assuming the second score is 'nil'
    }

    return result;
}

// ALTERNATIVE
#include <vector>
#include <string>

std::vector<int> scoreboard(const std::string &s) {
  std::vector<std::string> vec {"nil", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  
  std::string line;
  std::stringstream str(s);
  std::vector<int> score;
  
  while (std::getline(str, line, ' ')) {
    for (int i = 0; i < vec.size(); i++) {
      if (line.compare(vec[i]) == 0) { 
        score.push_back(i);
        break;
      }
    }
  }
  
  return score;
}
