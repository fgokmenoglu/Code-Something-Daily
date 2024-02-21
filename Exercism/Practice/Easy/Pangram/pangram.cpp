#include "pangram.h"

namespace pangram {
    std::string to_lowercase(const std::string& str) {
        std::string lower_str = str;
        std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
            [](unsigned char c) { return std::tolower(c); });
        
        return lower_str;
    }

    bool is_pangram(std::string in){
        bool out = true;
        std::string temp = to_lowercase(in);
        std::string letters = "abcdefghijklmnopqrstuvwxyz";

        for (auto &ch : letters)
            if (temp.find(ch) == std::string::npos)
                return false;

        return out;
    }
}  // namespace pangram

// ALTERNATIVE
#include "pangram.h"
#include <bitset>

namespace pangram {
	bool is_pangram(const std::string sentence) {
		std::bitset<26> alphabet_flags;

		for (const auto c : sentence) {
			if (isalpha(c)) {
				alphabet_flags.set(tolower(c) - 'a');

				if (alphabet_flags.all())
					return true;
			}
		}

		return false;
	}
}
