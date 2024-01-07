/*
 * There are two groups of hostile letters. 
 * The tension between left side letters and right side letters was too high and the war began. 
 * The letters called airstrike to help them in war - dashes and dots are spread throughout the battlefield. Who will win?
 * 
 * Task
 * Write a function that accepts a fight string which consists of only small letters and * which represents a bomb drop place. 
 * Return who wins the fight after bombs are exploded. 
 * When the left side wins return Left side wins!, and when the right side wins return Right side wins!. 
 * In other cases, return Let's fight again!.
 * 
 * The left side letters and their power: w - 4, p - 3, b - 2, s - 1
 * The right side letters and their power: m - 4, q - 3, d - 2, z - 1
 * The other letters don't have power and are only victims.
 * The * bombs kill the adjacent letters ( i.e. aa*aa => a___a, **aa** => ______ );
 * 
 * Example
 * AlphabetWar("s*zz");           //=> Right side wins!
 * AlphabetWar("*zd*qm*wp*bs*"); //=> Let's fight again!
 * AlphabetWar("zzzz*s*");       //=> Right side wins!
 * AlphabetWar("www*www****z");  //=> Left side wins!
*/
