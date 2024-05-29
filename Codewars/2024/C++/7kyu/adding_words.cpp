/*
 * Implement a class Arith such that
 * Input - Will be between zero and ten and will always be in lower case
 * Output - Word representation of the result of the addition. Should be in lower case
 */
#include <string>
#include <unordered_map>

using namespace std;

class Arith {
private:
    int value;
    unordered_map<string, int> strToNum;
    unordered_map<int, string> numToStr;

public:
    Arith(string number) {
        initMaps();
        value = strToNum[number];
    }

    string add(string number) {
        int result = value + strToNum[number];
        return numToStr[result];
    }

private:
    void initMaps() {
        strToNum = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
                    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
                    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
                    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
                    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}};
        
        for (const auto& pair : strToNum) {
            numToStr[pair.second] = pair.first;
        }
    }
};
