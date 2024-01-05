/*
 * TASK
 * You will be given three reels of different images and told at which index the reels stop. From this information your job is to return the score of the resulted reels.
 *
 * RULES
 * 1. There are always exactly three reels
 * 2. Each reel has 10 different items.
 * 3. The three reel inputs may be different.
 * 4. The spin array represents the index of where the reels finish.
 * 5. The three spin inputs may be different
 * 6. Three of the same is worth more than two of the same
 * 7. Two of the same plus one "Wild" is double the score.
 * 8. No matching items returns 0.
 *
 * SCORING
 * Item    Three of the same    Two of the same    Two of the same plus one Wild
 * Wild    100                  10                 N/A
 * Wild    90                   9                  18
 * Wild    80                   8                  16
 * Wild    70                   7                  14
 * Wild    60                   6                  12
 * Wild    50                   5                  10
 * Wild    40                   4                  8
 * Wild    30                   3                  6
 * Wild    20                   2                  4
 * Wild    10                   1                  2
 *
 * RETURNS
 * Return an integer of the score.
 *
 * EXAMPLE
 * reel1 = {"Wild","Star","Bell","Shell","Seven","Cherry","Bar","King","Queen","Jack"}
 * reel2 = {"Wild","Star","Bell","Shell","Seven","Cherry","Bar","King","Queen","Jack"}
 * reel3 = {"Wild","Star","Bell","Shell","Seven","Cherry","Bar","King","Queen","Jack"}
 * spin  = {5,5,5}
 * result = fruit({reel1, reel2, reel3}, spin)
 * 
 * reel1[5] == "Cherry"
 * reel2[5] == "Cherry"
 * reel3[5] == "Cherry"
 * 
 * Cherry + Cherry + Cherry == 50
 * 
 * result == 50
 */
#include <array>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unsigned fruit(const array<vector<string>, 3> &reels, const array<unsigned, 3> &spins) {
    // Map to hold the scoring values for each item
    unordered_map<string, unsigned> scores = {
        {"Wild", 100}, {"Star", 90}, {"Bell", 80}, {"Shell", 70}, {"Seven", 60},
        {"Cherry", 50}, {"Bar", 40}, {"King", 30}, {"Queen", 20}, {"Jack", 10}
    };

    // Get the items from the reels at the spun positions
    string first = reels[0][spins[0] % 10];
    string second = reels[1][spins[1] % 10];
    string third = reels[2][spins[2] % 10];

    // Count the occurrences of each item
    unordered_map<string, int> counts;
    counts[first]++;
    counts[second]++;
    counts[third]++;

    if (counts[first] == 3 || counts[second] == 3 || counts[third] == 3) {
      // If three of the same item
      return scores[first]; // Can return score of any, as all are same in this case
    } 
    else if (counts[first] == 2 || counts[second] == 2 || counts[third] == 2) {
      // If two of the same item
      string twoOfSame = counts[first] == 2 ? first : (counts[second] == 2 ? second : third);
      
      if (counts["Wild"] == 1) {
        // If two of the same plus one Wild
        return 2 * scores[twoOfSame] / 10;
      } 
      else {
        // Only two of the same
        return scores[twoOfSame] / 10;
      }
    } 
    else {
      return 0;      
    }
}
