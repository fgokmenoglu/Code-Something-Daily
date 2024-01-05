/*
 * Create a function that gives a personalized greeting. This function takes two parameters: name and owner.
 *
 * Use conditionals to return the proper message:
 *
 * case name equals owner	return 'Hello boss' otherwise	'Hello guest'
 */
#include <string>

std::string greet(const std::string& name, const std::string& owner) {
  if (name == owner)
    return "Hello boss";
  
  return "Hello guest";
}
