#include <string>
#include <vector>
#include <algorithm>

/* Task:
* You will need to return a boolean value if the base string can be
* expressed as the repetition of one subpattern.
* 
* This time there are two small changes. If a subpattern has been used,
* it will be present at least twice, meaning the subpattern has to be
* shorter than the original string. The strings you will be given might
* or might not be created repeating a given subpattern, then shuffling
* the result.
*
* For example:
* hasSubpattern("a") == false; //no repeated shorter sub-pattern, just one character
* hasSubpattern("aaaa") == true; //just one character repeated
* hasSubpattern("abcd") == false; //no repetitions
* hasSubpattern("babababababababa") == true; //repeated "ba"
* hasSubpattern("bbabbaaabbaaaabb") == true; //same as above, just shuffled
*
* Strings will never be empty and can be composed of any character
* (just consider upper- and lowercase letters as different entities)
* and can be pretty long (keep an eye on performances!).
*/

bool hasSubpattern(const std::string& str) {
    int n = str.length();
    if (n < 2) return false;  // A string of length 1 can't have a subpattern

    // Count the occurrences of each character
    std::vector<int> charCount(256, 0);
    for (char c : str) {
        charCount[c]++;
    }

    // Find the GCD of all character counts
    int gcd = charCount[str[0]];
    for (int count : charCount) {
        if (count > 0) {
            gcd = std::__gcd(gcd, count);
        }
    }

    // If GCD is 1, there's no subpattern
    if (gcd == 1) return false;

    // Check if all character counts are divisible by GCD
    for (int count : charCount) {
        if (count > 0 && count % gcd != 0) {
            return false;
        }
    }

    return true;
}
