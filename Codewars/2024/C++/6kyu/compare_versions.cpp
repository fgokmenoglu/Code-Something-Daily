/*
 * Karan's company makes software that provides different features based on the version of operating system of the user.
 *
 * To compare versions, Karan currently parses both version numbers as floats.
 *
 * While this worked for OS versions 10.6, 10.7, 10.8 and 10.9, the operating system company just released OS version 10.10. 
 * This causes his method to fail, as 10.9 is greater than 10.10 when interpreting both as numbers, despite being a lesser version.
 *
 * Help Karan by writing him a function which compares two versions, and returns whether or not the first one is greater than or equal to the second.
 * 
 * Specification notes:
 *
 * Versions are provided as strings of one or more integers separated by ..
 * The version strings will never be empty.
 * The two versions are not guaranteed to have an equal amount of sub-versions, when this happens assume that all missing sub-versions are zero.
 * Two versions which differ only by trailing zero sub-versions will never be given.
 */
#include <string>
#include <sstream>
#include <vector>

std::vector<int> splitVersion(const std::string& version) {
    std::vector<int> parts;
    std::stringstream ss(version);
    std::string part;
    while (std::getline(ss, part, '.')) {
        parts.push_back(std::stoi(part));
    }
    return parts;
}

bool compareVersions(const std::string& version1, const std::string& version2) {
    std::vector<int> v1 = splitVersion(version1);
    std::vector<int> v2 = splitVersion(version2);

    size_t maxLength = std::max(v1.size(), v2.size());
    v1.resize(maxLength, 0);  // Fill with zeros
    v2.resize(maxLength, 0);  // Fill with zeros

    for (size_t i = 0; i < maxLength; ++i) {
        if (v1[i] > v2[i]) {
            return true;
        }
        if (v1[i] < v2[i]) {
            return false;
        }
    }
    return true; // They are equal
}
