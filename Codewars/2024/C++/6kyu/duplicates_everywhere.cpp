/*
 * You are given a table, in which every key is a stringified number, 
 * and each corresponding value is an array of characters, e.g.
 *
 * {
 *  "1": ["A", "B", "C"],
 *  "2": ["A", "B", "D", "A"],
 * }
 *
 * Create a function that returns a table with the same keys, 
 * but each character should appear only once among the value-arrays, e.g.
 *
 * {
 *  "1": ["C"],
 *  "2": ["A", "B", "D"],
 * }
 *
 * Rules
 * Whenever two keys share the same character, they should be compared numerically, 
 * and the larger key will keep that character. 
 * That's why in the example above the array under the key "2" contains "A" and "B", as 2 > 1.
 * If duplicate characters are found in the same array, the first occurance should be kept.
 */
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(const msv &obj) {
    msv result;
    std::unordered_set<char> global_chars;

    // Sort keys in descending order
    std::vector<std::string> keys;
    for (const auto &pair : obj) {
        keys.push_back(pair.first);
    }
    std::sort(keys.begin(), keys.end(), [](const std::string &a, const std::string &b) {
        return std::stoi(a) > std::stoi(b);
    });

    // Process each key
    for (const auto &key : keys) {
        std::unordered_set<char> local_chars;
        std::vector<char> unique_chars;

        for (char c : obj.at(key)) {
            if (global_chars.find(c) == global_chars.end() && local_chars.find(c) == local_chars.end()) {
                unique_chars.push_back(c);
                global_chars.insert(c);
                local_chars.insert(c);
            }
        }

        // Always add the key to the result, even if the vector is empty
        result[key] = unique_chars;
    }

    return result;
}
