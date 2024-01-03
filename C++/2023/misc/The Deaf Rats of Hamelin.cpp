/*
 * Kata Task
 * How many deaf rats are there?
 * 
 * Legend
 * P = The Pied Piper
 * O~ = Rat going left
 * ~O = Rat going right
 *
 * Example
 * ex1 ~O~O~O~O P has 0 deaf rats
 * ex2 P O~ O~ ~O O~ has 1 deaf rat
 * ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats
 */

#include <string>

int countDeafRats(const std::string &town) {
    int deafRats = 0;
    size_t piperPos = town.find('P');
    std::string leftSide = town.substr(0, piperPos);
    std::string rightSide = town.substr(piperPos + 1);

    // Remove spaces for easier processing
    leftSide.erase(remove(leftSide.begin(), leftSide.end(), ' '), leftSide.end());
    rightSide.erase(remove(rightSide.begin(), rightSide.end(), ' '), rightSide.end());

    // Count deaf rats to the left of the Pied Piper
    for (size_t i = 0; i < leftSide.length(); i += 2) {
        if (leftSide[i] == '~' && i + 1 < leftSide.length() && leftSide[i + 1] == 'O') {
            // Rat facing right on the left side of the Piper
        } else {
            deafRats++; // Deaf rat
        }
    }

    // Count deaf rats to the right of the Pied Piper
    for (size_t i = 0; i < rightSide.length(); i += 2) {
        if (rightSide[i] == 'O' && i + 1 < rightSide.length() && rightSide[i + 1] == '~') {
            // Rat facing left on the right side of the Piper
        } else {
            deafRats++; // Deaf rat
        }
    }

    return deafRats;
}

