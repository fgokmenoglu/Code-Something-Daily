/*
 * Paul is an excellent coder and sits high on the CW leaderboard. 
 * He solves kata like a banshee but would also like to lead a normal life, with other activities. 
 * But he just can't stop solving all the kata!!
 * 
 * Given an array (x) you need to calculate the Paul Misery Score. 
 * The values are worth the following points:
 * 
 * kata = 5
 * Petes kata = 10
 * life = 0
 * eating = 1
 * The Misery Score is the total points gained from the array. Once you have the total, return as follows:
 * 
 * < 40 = 'Super happy!'
 * < 70 >= 40 = 'Happy!'
 * < 100 >= 70 = 'Sad!'
 * > 100 = 'Miserable!'
 */
#include <string>
#include <vector>
#include <unordered_map>

std::string paul(const std::vector<std::string>& x) {
    std::unordered_map<std::string, int> points = {
        {"kata", 5},
        {"Petes kata", 10},
        {"life", 0},
        {"eating", 1}
    };

    int score = 0;

    for (const std::string& activity : x) {
        score += points[activity]; // Add points for each activity
    }

    if (score < 40) {
        return "Super happy!";
    } else if (score < 70) {
        return "Happy!";
    } else if (score < 100) {
        return "Sad!";
    } else {
        return "Miserable!";
    }
}

// ALTERNATIVE
#include <string>
#include <vector>

std::string paul(const std::vector<std::string>& x) {
    std::map<std::string, int> m = {
        {"kata",       5  },
        {"Petes kata", 10 },
        {"eating",     1  }
    };
    
    int n = 0;
    for (std::string s: x) n += m[s];
    switch (n) {
        case  0 ... 39 : return "Super happy!";
        case 40 ... 69 : return "Happy!";
        case 70 ... 99 : return "Sad!";
        default        : return "Miserable!";
    }
}
