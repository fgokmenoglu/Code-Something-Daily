/*
 * You will be given a string (x) featuring a cat 'C' and a mouse 'm'. 
 * The rest of the string will be made up of '.'.
 * You need to find out if the cat can catch the mouse from it's current position. 
 * The cat can jump over three characters. So:
 * C.....m returns 'Escaped!' <-- more than three characters between
 * C...m returns 'Caught!' <-- as there are three characters between the two, the cat can jump.
 */
#include <string>

std::string cat_mouse(std::string x) {
  return (x.find('m') - x.find('C')) <= 4 || (x.find('C') - x.find('m')) <= 4 ? "Caught!" : "Escaped!";
}

// ALTERNATIVE
std::string cat_mouse( const std::string& s ) {
  return s.size() <= 5 ? "Caught!" : "Escaped!";
}
