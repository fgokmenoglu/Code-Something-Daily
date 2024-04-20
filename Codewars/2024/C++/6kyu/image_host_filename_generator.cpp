/*
 * You are developing an image hosting website.
 * You have to create a function for generating random and unique image filenames.
 * Create a function for generating a random 6 character string which will be used to access the photo URL.
 * To make sure the name is not already in use, you are given access to an PhotoManager object.
 * You can call it like so to make sure the name is unique
 * // at this point, the website has only one photo, hosted on the 'ABCDEF' url
 * photoManager.nameExists("ABCDEF"); // returns true
 * photoManager.nameExists("BBCDEF"); // returns false
 * Note: We consider two names with same letters but different cases to be unique.
 */
#include <string>
#include <random>

std::string generateName() {
    // Length of the random string to be generated
    const int NAME_LENGTH = 6;
    // Characters allowed in the filename
    const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Engine for random number generation
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<size_t> distribution(0, CHARACTERS.size() - 1);

    // Function to generate a random string of fixed length
    auto generateRandomString = [&]() -> std::string {
        std::string result;
        result.reserve(NAME_LENGTH);
        for (int i = 0; i < NAME_LENGTH; ++i) {
            result += CHARACTERS[distribution(generator)];
        }
        return result;
    };

    // Generate a unique name
    std::string newName;
    do {
        newName = generateRandomString();
    } while (photoManager.nameExists(newName));

    return newName;
}
