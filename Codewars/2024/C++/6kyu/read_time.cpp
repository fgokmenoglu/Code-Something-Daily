/*
 * Given time in 24-hour format, convert it to words.
 * 
 * For example:
 * 13:00 = one o'clock 
 * 13:09 = nine minutes past one 
 * 13:15 = quarter past one 
 * 13:29 = twenty nine minutes past one
 * 13:30 = half past one 
 * 13:31 = twenty nine minutes to two
 * 13:45 = quarter to two 
 * 00:48 = twelve minutes to one
 * 00:08 = eight minutes past midnight
 * 12:00 = twelve o'clock
 * 00:00 = midnight
 * 
 * Note: 
 * If minutes == 0, use 'o'clock'. 
 * If minutes <= 30, use 'past', and for minutes > 30, use 'to'.
 */
#include <string>
#include <vector>
#include <sstream>

std::string solve(std::string time) {
    std::vector<std::string> numbers = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                                        "eighteen", "nineteen", "twenty"};
    
    std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty"};

    int hour = std::stoi(time.substr(0, 2));
    int minute = std::stoi(time.substr(3, 2));

    std::string result;

    auto numberToWords = [&](int num) -> std::string {
        if (num <= 20) return numbers[num];
        return tens[num / 10] + (num % 10 ? " " + numbers[num % 10] : "");
    };

    if (minute == 0) {
        if (hour == 0) return "midnight";
        if (hour == 12) return "twelve o'clock";
        result = numbers[hour % 12] + " o'clock";
    } else if (minute <= 30) {
        if (minute == 15) {
            result = "quarter past ";
        } else if (minute == 30) {
            result = "half past ";
        } else {
            result = numberToWords(minute) + " minute" + (minute == 1 ? " " : "s ") + "past ";
        }
        result += (hour == 0) ? "midnight" : numbers[hour == 12 ? 12 : hour % 12];
    } else {
        int minutesTo = 60 - minute;
        hour = (hour + 1) % 24;
        if (minutesTo == 15) {
            result = "quarter to ";
        } else {
            result = numberToWords(minutesTo) + " minute" + (minutesTo == 1 ? " " : "s ") + "to ";
        }
        result += (hour == 0) ? "midnight" : numbers[hour == 12 ? 12 : hour % 12];
    }

    return result;
}
