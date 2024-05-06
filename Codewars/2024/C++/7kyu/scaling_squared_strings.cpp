/*
 * You are given a string of n lines, each substring being n characters long. For example: s = "abcd\nefgh\nijkl\nmnop"
 * We will study the "horizontal" and the "vertical" scaling of this square of strings.
 * 
 * A k-horizontal scaling of a string consists of replicating k times each character of the string (except '\n').
 * Example: 2-horizontal scaling of s: => "aabbccdd\neeffgghh\niijjkkll\nmmnnoopp"
 * 
 * A v-vertical scaling of a string consists of replicating v times each part of the squared string.
 * Example: 2-vertical scaling of s: => "abcd\nabcd\nefgh\nefgh\nijkl\nijkl\nmnop\nmnop"
 * 
 * Function scale(strng, k, v) will perform a k-horizontal scaling and a v-vertical scaling.
 * Example: a = "abcd\nefgh\nijkl\nmnop"
 * scale(a, 2, 3) --> "aabbccdd\naabbccdd\naabbccdd\neeffgghh\neeffgghh\neeffgghh\niijjkkll\niijjkkll\niijjkkll\nmmnnoopp\nmmnnoopp\nmmnnoopp"
 *
 * Task:
 * Write function scale(strng, k, v) k and v will be positive integers. If strng == "" return "".
 */
#include <string>
#include <vector>
#include <sstream>

class ScalingSqStrings {
public:
    static std::string scale(const std::string &strng, int k, int v) {
        if (strng.empty()) return "";

        std::vector<std::string> lines;
        std::istringstream iss(strng);
        std::string line;

        // Read lines from input string
        while (std::getline(iss, line)) {
            lines.push_back(line);
        }

        std::string result;

        // Process each line
        for (auto &orig_line : lines) {
            std::string h_scaled_line;

            // Horizontal scaling
            for (char c : orig_line) {
                h_scaled_line.append(k, c);
            }

            // Vertical scaling
            for (int i = 0; i < v; ++i) {
                if (!result.empty()) result.append("\n");
                result.append(h_scaled_line);
            }
        }

        return result;
    }
};
