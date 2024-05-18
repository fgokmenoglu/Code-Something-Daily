/*
 * A squared string is a string of n lines, each substring being n characters long. 
 * We are given two n-squared strings. For example:
 * s1 = "abcd\nefgh\nijkl\nmnop" s2 = "qrst\nuvwx\nyz12\n3456"
 *
 * Let us build a new string strng of size (n + 1) x n in the following way:
 * The first line of strng has the first char of the first line of s1 plus the chars of the last line of s2.
 * The second line of strng has the first two chars of the second line of s1 plus the chars of the penultimate line of s2 except the last char
 * and so on until the nth line of strng has the n chars of the nth line of s1 plus the first char of the first line of s2.
 * Calling this function compose(s1, s2) we have:
 *
 * compose(s1, s2) -> "a3456\nefyz1\nijkuv\nmnopq"
 * or printed:
 * abcd    qrst  -->  a3456
 * efgh    uvwx       efyz1
 * ijkl    yz12       ijkuv
 * mnop    3456       mnopq
 */
#include <vector>
#include <sstream>

class ComposeSqStrings {
public:
    static std::string compose(const std::string &s1, const std::string &s2) {
        // Split the input strings into lines
        std::vector<std::string> lines1 = splitLines(s1);
        std::vector<std::string> lines2 = splitLines(s2);
        
        int n = lines1.size();
        std::vector<std::string> resultLines(n);
        
        // Construct each line of the result
        for (int i = 0; i < n; ++i) {
            std::string prefix = lines1[i].substr(0, i + 1);
            std::string suffix = lines2[n - 1 - i].substr(0, n - i);
            resultLines[i] = prefix + suffix;
        }
        
        // Combine the result lines into a single string
        return joinLines(resultLines);
    }

private:
    // Helper function to split a string into lines
    static std::vector<std::string> splitLines(const std::string &str) {
        std::vector<std::string> lines;
        std::istringstream stream(str);
        std::string line;
        while (std::getline(stream, line)) {
            lines.push_back(line);
        }
        return lines;
    }
    
    // Helper function to join lines into a single string
    static std::string joinLines(const std::vector<std::string> &lines) {
        std::ostringstream stream;
        for (size_t i = 0; i < lines.size(); ++i) {
            if (i > 0) {
                stream << "\n";
            }
            stream << lines[i];
        }
        return stream.str();
    }
};
