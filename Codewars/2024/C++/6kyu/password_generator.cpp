/*
 * You need to write a password generator that meets the following criteria:
 * 
 *     6 - 20 characters long
 *     contains at least one lowercase letter
 *     contains at least one uppercase letter
 *     contains at least one number
 *     contains only alphanumeric characters (no special characters)
 * 
 * Return the random password as a string.
 * Note: "randomness" is checked by counting the characters used in the generated passwords - all characters should have less than 50% occurance. Based on extensive tests, the normal rate is around 35%.
 */
#include <string>
#include <random>
#include <algorithm>
#include <stdexcept>

std::string password_gen() {
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string all_chars = lowercase + uppercase + numbers;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> length_dist(6, 20);
    std::uniform_int_distribution<> char_dist(0, all_chars.length() - 1);

    int length = length_dist(gen);
    std::string password(length, ' ');

    bool has_lower = false, has_upper = false, has_number = false;

    for (int i = 0; i < length; ++i) {
        char c = all_chars[char_dist(gen)];
        password[i] = c;
        
        if (std::islower(c)) has_lower = true;
        else if (std::isupper(c)) has_upper = true;
        else if (std::isdigit(c)) has_number = true;
    }

    // Ensure all criteria are met
    if (!has_lower || !has_upper || !has_number) {
        return password_gen(); // Recursively generate a new password
    }

    return password;
}
