/*
 * Introduction
 * The GADERYPOLUKI is a simple substitution cypher used in scouting to encrypt messages. 
 * The encryption is based on short, easy to remember key. 
 * The key is written as paired letters, which are in the cipher simple replacement.
 * The most frequently used key is "GA-DE-RY-PO-LU-KI".
 *  G => A
 *  g => a
 *  a => g
 *  A => G
 *  D => E
 *  etc.
 * The letters, which are not on the list of substitutes, stays in the encrypted text without changes.
 * Other keys often used by Scouts:
 *  PO-LI-TY-KA-RE-NU
 *  KA-CE-MI-NU-TO-WY
 *  KO-NI-EC-MA-TU-RY
 *  ZA-RE-WY-BU-HO-KI
 *  BA-WO-LE-TY-KI-JU
 *  RE-GU-LA-MI-NO-WY
 *
 * Task
 * Your task is to help scouts to encrypt and decrypt thier messages. 
 * Write the Encode and Decode functions.
 * Input/Output
 * The function should have two parameters.
 * The message input string consists of lowercase and uperrcase characters and whitespace character.
 * The key input string consists of only lowercase characters.
 * The substitution has to be case-sensitive.
 * 
 * Example
 *  Encode("ABCD", "agedyropulik");             // => GBCE 
 *  Encode("Ala has a cat", "gaderypoluki");    // => Gug hgs g cgt 
 *  Decode("Dkucr pu yhr ykbir","politykarenu") // => Dance on the table
 *  Decode("Hmdr nge brres","regulaminowy")  // => Hide our beers
 */
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

unordered_map<char, char> createSubstitutionMap(const string& key) {
    unordered_map<char, char> substitutionMap;
    for (size_t i = 0; i < key.length(); i += 2) {
        char a = key[i];
        char b = key[i + 1];
        substitutionMap[a] = b;
        substitutionMap[b] = a;
        substitutionMap[toupper(a)] = toupper(b);
        substitutionMap[toupper(b)] = toupper(a);
    }
    return substitutionMap;
}

string encode(string str, string key) {
    auto substitutionMap = createSubstitutionMap(key);
    string result;
    
    for (char c : str) {
        if (substitutionMap.find(c) != substitutionMap.end()) {
            result += substitutionMap[c];
        } else {
            result += c;
        }
    }
    
    return result;
}

string decode(string str, string key) {
    // For this cipher, encoding and decoding are the same process
    return encode(str, key);
}
