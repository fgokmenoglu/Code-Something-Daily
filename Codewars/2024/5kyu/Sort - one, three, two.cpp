/*
 * Input
 * Range is 0-999
 * There may be duplicates
 * The array may be empty
 * 
 * Example
 * Input: 1, 2, 3, 4
 * Equivalent names: "one", "two", "three", "four"
 * Sorted by name: "four", "one", "three", "two"
 * Output: 4, 1, 3, 2
 *
 * Notes
 * Don't pack words together:
 * e.g. 99 may be "ninety nine" or "ninety-nine"; but not "ninetynine"
 * e.g 101 may be "one hundred one" or "one hundred and one"; but not "onehundredone"
 * Don't fret about formatting rules, because if rules are consistently applied it has no effect anyway:
 * e.g. "one hundred one", "one hundred two"; is same order as "one hundred and one", "one hundred and two"
 * e.g. "ninety eight", "ninety nine"; is same order as "ninety-eight", "ninety-nine"
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Dinglemouse {
  private:
    static unordered_map<int, string> numberToWords;
    static string numberToEnglish(int number);

  public:
    static vector<int> sort(const vector<int> &array);
};

unordered_map<int, string> Dinglemouse::numberToWords = {
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
    {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
    {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"},
    {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"},
    {19, "nineteen"}, {20, "twenty"}, {30, "thirty"}, {40, "forty"},
    {50, "fifty"}, {60, "sixty"}, {70, "seventy"}, {80, "eighty"},
    {90, "ninety"}
};

string Dinglemouse::numberToEnglish(int number) {
    if (number == 0) return numberToWords[0];
    if (numberToWords.find(number) != numberToWords.end()) return numberToWords[number];

    string result;
    if (number >= 100) {
        result += numberToWords[number / 100] + " hundred";
        if (number % 100 != 0) result += " and ";
        number %= 100;
    }

    if (number > 0) {
        if (numberToWords.find(number) != numberToWords.end()) {
            result += numberToWords[number];
        } else {
            result += numberToWords[number - number % 10] + " " + numberToWords[number % 10];
        }
    }

    return result;
}

vector<int> Dinglemouse::sort(const vector<int> &array) {
    vector<pair<string, int>> namedNumbers;
    for (int num : array) {
        namedNumbers.emplace_back(numberToEnglish(num), num);
    }

    std::sort(namedNumbers.begin(), namedNumbers.end());

    vector<int> sortedArray;
    for (auto &pair : namedNumbers) {
        sortedArray.push_back(pair.second);
    }

    return sortedArray;
}
