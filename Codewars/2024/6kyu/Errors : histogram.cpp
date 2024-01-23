/*
 * In a factory a printer prints labels for boxes. 
 * The printer uses colors which, for the sake of simplicity, 
 * are named with letters from a to z (except letters u, w, x or z that are for errors).
 * The colors used by the printer are recorded in a control string. 
 * For example a control string would be aaabbbbhaijjjm meaning that the printer used three times color a, 
 * four times color b, one time color h then one time color a... and so on.
 * Sometimes there are problems: lack of colors, technical malfunction and a control string is produced 
 * e.g. uuaaaxbbbbyyhwawiwjjjwwxym where errors are reported with letters u, w, x or z.
 * You have to write a function hist which given a string will output the errors as a string representing a histogram of the encountered errors.
 * Format of the output string:
 * letter (error letters are sorted in alphabetical order) in a field of 2 characters, 
 * a white space, number of error for that letter in a field of 6, 
 * as many "*" as the number of errors for that letter and "\r" (or "\n" depending on the langauge).
 * The string has a length greater or equal to one and contains only letters from a to z.
 * Examples
 * s="uuaaaxbbbbyyhwawiwjjjwwxym"
 * hist(s) => "u  2     **\rw  5     *****\rx  2     **"
 * or with dots to see white spaces:
 *
 * hist(s) => "u..2.....**\rw..5.....*****\rx..2.....**"
 * s="uuaaaxbbbbyyhwawiwjjjwwxymzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
 * hist(s) => "u..2.....**\rw..5.....*****\rx..2.....**\rz..31....*******************************"
 */
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

std::string hist(const std::string &s) {
    std::stringstream out;

    int u_count = std::count(s.begin(), s.end(), 'u');
    int w_count = std::count(s.begin(), s.end(), 'w'); 
    int x_count = std::count(s.begin(), s.end(), 'x'); 
    int z_count = std::count(s.begin(), s.end(), 'z');

    if (u_count > 0) {
        out << std::left << std::setw(2) << 'u' << ' ' << std::setw(6) << u_count << std::string(u_count, '*') << "\r";
    }
    if (w_count > 0) {
        out << std::left << std::setw(2) << 'w' << ' ' << std::setw(6) << w_count << std::string(w_count, '*') << "\r";
    }
    if (x_count > 0) {
        out << std::left << std::setw(2) << 'x' << ' ' << std::setw(6) << x_count << std::string(x_count, '*') << "\r";
    }
    if (z_count > 0) {
        out << std::left << std::setw(2) << 'z' << ' ' << std::setw(6) << z_count << std::string(z_count, '*') << "\r";
    }
  
    return out.str();
}
