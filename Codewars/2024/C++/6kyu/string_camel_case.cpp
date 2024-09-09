#include <string>
#include <cctype>

// Complete the method/function so that it converts dash/underscore delimited words into camel casing.
// The first word within the output should be capitalized only if the original word was capitalized
// (known as Upper Camel Case, also often referred to as Pascal case).
// The next words should be always capitalized.

std::string to_camel_case(std::string text) {
    if (text.empty()) {
        return "";
    }

    std::string result;
    bool capitalize_next = false;

    for (size_t i = 0; i < text.length(); ++i) {
        if (text[i] == '-' || text[i] == '_') {
            capitalize_next = true;
        } else {
            if (capitalize_next) {
                result += std::toupper(text[i]);
                capitalize_next = false;
            } else if (i == 0 || std::isupper(text[i])) {
                result += text[i]; // Keep the first character and already capitalized letters as is
            } else {
                result += std::tolower(text[i]);
            }
        }
    }

    return result;
}
