/*
 * Introduction
 * The GADERYPOLUKI is a simple substitution cypher used in scouting to encrypt messages. 
 * The encryption is based on short, easy to remember key. 
 * The key is written as paired letters, which are in the cipher simple replacement.
 * The most frequently used key is "GA-DE-RY-PO-LU-KI".
 * G => A
 * g => a
 * a => g
 * A => G
 * D => E
 * etc.
 * The letters, which are not on the list of substitutes, stays in the encrypted text without changes.
 *
 * Task
 * Your task is to help scouts to encrypt and decrypt thier messages. 
 * Write the Encode and Decode functions.
 *
 * Input/Output
 * The input string consists of lowercase and uperrcase characters and white. 
 * The substitution has to be case-sensitive.
 *
 * Example
 *  Encode("ABCD")          // => GBCE 
 *  Encode("Ala has a cat") // => Gug hgs g cgt 
 *  Encode("gaderypoluki"); // => agedyropulik
 *  Decode("Gug hgs g cgt") // => Ala has a cat 
 *  Decode("agedyropulik")  // => gaderypoluki
 *  Decode("GBCE")          // => ABCD
 */
#include <string>
#include <unordered_map>

// Create substitution map
std::unordered_map<char, char> createSubstitutionMap(const std::string& key) {
    std::unordered_map<char, char> map;
    for (size_t i = 0; i < key.length(); i += 2) {
        map[key[i]] = key[i + 1];
        map[key[i + 1]] = key[i];
        map[std::tolower(key[i])] = std::tolower(key[i + 1]);
        map[std::tolower(key[i + 1])] = std::tolower(key[i]);
    }
    return map;
}

// Global substitution map
const std::unordered_map<char, char> substitutionMap = createSubstitutionMap("GADERYPOLUKI");

std::string encode(const std::string& str)
{
    std::string result = str;
    for (char& c : result) {
        auto it = substitutionMap.find(c);
        if (it != substitutionMap.end()) {
            c = it->second;
        }
    }
    return result;
}

std::string decode(const std::string& str)
{
    return encode(str); // Since the cipher is symmetric, decode is the same as encode
}
