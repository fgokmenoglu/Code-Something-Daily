#include <string>
#include <vector>

/*
 * Task:
 * Implement a function which behaves like the uniq command in UNIX.
 * It takes as input a sequence and returns a sequence in which all duplicate
 * elements following each other have been reduced to one instance.
 * 
 * Example:
 * ["a", "a", "b", "b", "c", "a", "b", "c"]  =>  ["a", "b", "c", "a", "b", "c"]
 */

std::vector<std::string> uniq(const std::vector<std::string> &v) {
    if (v.empty()) {
        return {};
    }

    std::vector<std::string> result;
    result.push_back(v[0]);

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] != v[i-1]) {
            result.push_back(v[i]);
        }
    }

    return result;
}
