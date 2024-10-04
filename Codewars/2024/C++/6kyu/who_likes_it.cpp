#include <string>
#include <vector>

/**
 * @brief Generates a display text for people who like an item
 * 
 * This function takes an array of names and returns a string describing who likes the item.
 * The output format changes based on the number of names in the array:
 * - For 0 names: "no one likes this"
 * - For 1 name: "[Name] likes this"
 * - For 2 names: "[Name1] and [Name2] like this"
 * - For 3 names: "[Name1], [Name2] and [Name3] like this"
 * - For 4 or more names: "[Name1], [Name2] and [N] others like this"
 *   where N is the number of remaining names
 *
 * @param names A vector of strings containing the names of people who like the item
 * @return std::string The formatted display text
 */
std::string likes(const std::vector<std::string> &names)
{
    switch(names.size()) {
        case 0:
            return "no one likes this";
        case 1:
            return names[0] + " likes this";
        case 2:
            return names[0] + " and " + names[1] + " like this";
        case 3:
            return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default:
            return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}
