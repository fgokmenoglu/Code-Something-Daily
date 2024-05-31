#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

// String Splitting
std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// String Joining
std::string joinStrings(const std::vector<std::string>& strings, char delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < strings.size(); ++i) {
        oss << strings[i];
        if (i != strings.size() - 1) {
            oss << delimiter;
        }
    }
    return oss.str();
}

// Removing Leading and Trailing Whitespace
std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        start++;
    }

    auto end = str.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

// String Case Conversion
std::string toUpperCase(const std::string& str) {
    std::string result(str);
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string toLowerCase(const std::string& str) {
    std::string result(str);
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

/**
 * @brief Reverses the characters in a given string.
 *
 * This function takes a string as input and returns a new string
 * where the characters are in reverse order. It uses the
 * `std::reverse` algorithm from the STL to perform the reversal.
 *
 * @param str The input string to be reversed.
 * @return A new string with characters in reverse order.
 *
 * @example
 * std::string original = "Hello, World!";
 * std::string reversed = reverseString(original);
 * // reversed == "!dlroW ,olleH"
 */
std::string reverseString(const std::string& str) {
    std::string reversedStr(str);
    std::reverse(reversedStr.begin(), reversedStr.end());
    return reversedStr;
}

int main() {
    // String Split Example
    std::string str = "one,two,three,four";
    std::vector<std::string> tokens = splitString(str, ',');

    std::cout << "Split result:" << std::endl;
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    // String Join Example
    std::vector<std::string> strings = { "one", "two", "three", "four" };
    std::string joinedString = joinStrings(strings, ',');

    std::cout << "Joined result: " << joinedString << std::endl;

    // Removing Leading and Trailing Whitespace Example
    std::string str2 = "   Hello, World!   ";
    std::string trimmedStr = trim(str2);

    std::cout << "Original: '" << str2 << "'" << std::endl;
    std::cout << "Trimmed: '" << trimmedStr << "'" << std::endl;

    // String Case Conversion Example
    std::string upperStr = toUpperCase(str);
    std::string lowerStr = toLowerCase(str);

    std::cout << "Original: " << str << std::endl;
    std::cout << "Uppercase: " << upperStr << std::endl;
    std::cout << "Lowercase: " << lowerStr << std::endl;

    // String Reversal Example
    std::string reversedStr = reverseString(str);

    std::cout << "Original: " << str << std::endl;
    std::cout << "Reversed: " << reversedStr << std::endl;

    // Other String Operation Examples
    // Length and size
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Size: " << str.size() << std::endl;

    // Accessing characters
    std::cout << "First character: " << str[0] << std::endl;
    std::cout << "Last character: " << str.at(str.size() - 1) << std::endl;

    // Finding substrings
    size_t pos = str.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl;
    }

    // Substring
    std::string sub = str.substr(7, 5);
    std::cout << "Substring: " << sub << std::endl;

    // Appending
    str.append(" How are you?");
    std::cout << "Appended string: " << str << std::endl;

    // Inserting
    str.insert(13, "beautiful ");
    std::cout << "Inserted string: " << str << std::endl;

    // Erasing
    str.erase(13, 10); // Remove "beautiful "
    std::cout << "Erased string: " << str << std::endl;

    // Replacing
    str.replace(7, 5, "Universe");
    std::cout << "Replaced string: " << str << std::endl;

    return 0;
}
