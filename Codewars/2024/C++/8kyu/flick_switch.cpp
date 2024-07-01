/*
 * Create a function that always returns True/true 
 * for every item in a given list. However, 
 * if an element is the word 'flick', 
 * switch to always returning the opposite boolean value.
 *
 * Examples
 * ['codewars', 'flick', 'code', 'wars'] ➞ [True, False, False, False]
 * ['flick', 'chocolate', 'adventure', 'sunshine'] ➞ [False, False, False, False]
 * ['bicycle', 'jarmony', 'flick', 'sheep', 'flick'] ➞ [True, True, False, False, True]
 *
 * Notes
 * "flick" will always be given in lowercase.
 * A list may contain multiple flicks.
 * Switch the boolean value on the same element as the flick itself.
 */
#include <vector>
#include <string>

std::vector<bool> flick_switch(const std::vector<std::string>& arr) {
    std::vector<bool> result;
    bool current_state = true;

    for (const auto& element : arr) {
        if (element == "flick") {
            current_state = !current_state;
        }
        result.push_back(current_state);
    }

    return result;
}
