/*
 * John wants to decorate the walls of a room with wallpaper. He wants a fool-proof method for getting it right.
 * John knows that the rectangular room has a length of l meters, a width of w meters, a height of h meters. 
 * The standard width of the rolls he wants to buy is 52 centimeters. 
 * The length of a roll is 10 meters. He bears in mind however, 
 * that it’s best to have an extra length of wallpaper handy 
 * in case of mistakes or miscalculations so he wants to buy a length 15% greater than the one he needs.
 * Last time he did these calculations he got a headache, so could you help John?
 *
 * Task
 * Your function wallpaper(l, w, h) should return as a plain English word in lower case the number of rolls he must buy.
 *
 * Example
 * wallpaper(4.0, 3.5, 3.0) should return "ten"
 * wallpaper(0.0, 3.5, 3.0) should return "zero"
 *
 * Notes
 * All rolls (even with incomplete width) are put edge to edge.
 * 0 <= l, w, h (floating numbers); it can happens that w * h * l is zero
 * The integer r (number of rolls) will always be less or equal to 20
 * The number of rolls will be a positive or null integer (not a plain English word; this number can be greater than 20)
 * In Coffeescript, Javascript, Python, Ruby and Scala the English numbers are preloaded and can be accessed as:
 * numbers = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", 
 * "nine", "ten", "eleven", "twelve","thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]
 * For other languages it is not preloaded and you can instead copy the above list if you desire.
 */
#include <string>
#include <vector>
#include <cmath> // For std::ceil

using namespace std;

class Wallpaper {
  public:
    static string wallPaper(double l, double w, double h) {
        // Array of numbers in words
        vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", 
                                  "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
                                  "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

        // Check for zero values
        if (l == 0 || w == 0 || h == 0) return numbers[0];

        // Calculate the total area to cover
        double totalArea = 2 * (l * h + w * h);

        // Roll dimensions in meters
        double rollWidth = 0.52; // 52 cm in meters
        double rollLength = 10; // Length of the roll in meters

        // Area covered by one roll
        double rollArea = rollWidth * rollLength;

        // Total rolls needed, including 15% extra
        int totalRolls = ceil((totalArea * 1.15) / rollArea);

        // Return the number in words
        return totalRolls > 20 ? "more than twenty" : numbers[totalRolls];
    }
};

