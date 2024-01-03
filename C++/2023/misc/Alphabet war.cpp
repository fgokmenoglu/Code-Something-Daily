/*
 * Introduction
 * There is a war and nobody knows - the alphabet war!
 * There are two groups of hostile letters. The tension between left side letters and right side letters was too high and the war began.
 * 
 * Task
 * Write a function that accepts fight string consists of only small letters and return who wins the fight. When the left side wins return Left side wins!, when the right side wins return Right side wins!, in other case return Let's fight again!.
 * 
 * The left side letters and their power:
 * 
 * w - 4
 * p - 3
 * b - 2
 * s - 1
 *
 * The right side letters and their power:
 * 
 * m - 4
 * q - 3
 * d - 2
 * z - 1
 *
 * The other letters don't have power and are only victims.
 * 
 * Example
 * AlphabetWar("z");        //=> Right side wins!
 * AlphabetWar("zdqmwpbs"); //=> Let's fight again!
 * AlphabetWar("zzzzs");    //=> Right side wins!
 * AlphabetWar("wwwwwwz");  //=> Left side wins!
 */
#include <string>

using namespace std;

string alphabetWar(string fight) {
  int n(0);
  
  for (auto c(fight.begin()); c != fight.end(); ++c)
    switch (*c) {
      case 'w': ++n;
      case 'p': ++n;
      case 'b': ++n;
      case 's': ++n; break;
      case 'm': --n;
      case 'q': --n;
      case 'd': --n;
      case 'z': --n;
      default: break;
    }
  
  return !n ? "Let's fight again!" : n > 0 ? "Left side wins!" : "Right side wins!";
}

// ALTERNATIVE
#include <string>
#include <map>
using namespace std;

std::map<char,int> warriors = {
// left
  {'w',4},
  {'p',3},
  {'b',2},
  {'s',1},
// right
  {'m',-4},
  {'q',-3},
  {'d',-2},
  {'z',-1}
};
 
string alphabetWar(string fight) {
  int result = 0;
  
  for(auto c : fight)
    result += warriors[c];

  if (result > 0) return "Left side wins!";
  else if (result < 0) return "Right side wins!";
  else return "Let's fight again!";
}
