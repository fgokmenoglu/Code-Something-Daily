/*
 * Write a function that accepts reinforces array of strings and airstrikes array of strings.
 * The reinforces strings consist of only small letters. The size of each string in reinforces array is the same.
 * The airstrikes strings consists of * and white spaces. The size of each airstrike may vary. There may be also no airstrikes at all.
 *
 * The first row in reinforces array is the current battlefield. 
 * Whenever some letter is killed by bomb, it's replaced by a letter from next string in reinforces array on the same position.
 * The airstrike always starts from the beginning of the battlefield.
 * The * means a bomb drop place. The each * bomb kills letter only on the battelfield. The bomb kills letter on the same index on battlefield plus the adjacent letters.
 * The letters on the battlefield are replaced after airstrike is finished.
 * Return string of letters left on the battlefield after the last airstrike. 
 * In case there is no any letter left in reinforces on specific position, return _.
 *
 * reinforces = [ "abcdefg",
 *                "hijklmn"];
 * airstrikes = [ "   *   ",
 *                "*  *   "];
 *               
 * The battlefield  is     : "abcedfg".
 * The first airstrike    : "   *   "  
 * After first airstrike  : "ab___fg"
 * Reinforces are comming : "abjklfg"
 * The second airstrike   : "*  *   "
 * After second airstrike : "_____fg"
 * Reinforces are coming  : "hi___fg"
 * No more airstrikes => return "hi___fg"
 */
#include <string>
#include <vector>

std::string alphabet_war(const std::vector<std::string>& reinforces,
                         const std::vector<std::string>& airstrikes)
{
    if (reinforces.empty()) return "";
    
    std::string battlefield = reinforces[0];
    std::size_t battlefield_size = battlefield.size();
    std::vector<std::size_t> reinforce_levels(battlefield_size, 0);

    // Process each airstrike
    for (const auto& airstrike : airstrikes) {
        std::vector<bool> hit(battlefield_size, false);
        
        // Mark hit positions
        for (std::size_t i = 0; i < airstrike.size() && i < battlefield_size; ++i) {
            if (airstrike[i] == '*') {
                hit[i] = true;
                if (i > 0) hit[i-1] = true;
                if (i < battlefield_size - 1) hit[i+1] = true;
            }
        }
        
        // Apply damage and reinforcements
        for (std::size_t i = 0; i < battlefield_size; ++i) {
            if (hit[i]) {
                reinforce_levels[i]++;
                if (reinforce_levels[i] < reinforces.size()) {
                    battlefield[i] = reinforces[reinforce_levels[i]][i];
                } else {
                    battlefield[i] = '_';
                }
            }
        }
    }

    return battlefield;
}
