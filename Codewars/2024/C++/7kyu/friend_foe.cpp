#include <string>
#include <vector>

/* Code Description:
* Make a program that filters a list of strings and returns a list with only your friends name in it.
* If a name has exactly 4 letters in it, you can be sure that it has to be a friend of yours! Otherwise, you can be sure he's not...
* Input = {"Ryan", "Kieran", "Jason", "Yous"}
* Output = {"Ryan", "Yous"}
* Input = {"Peter", "Stephen", "Joe"}
* Output = {}
* Input strings will only contain letters. 
* Note: keep the original order of the names in the output.
*/
using Names_t = std::vector<std::string>;

Names_t friendOrFoe(const Names_t& input) {
  Names_t friends;
  for (const auto& name : input)
    if (name.size() == 4) friends.push_back(name);
  return friends;
}
