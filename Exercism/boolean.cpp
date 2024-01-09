/*
 * INTRODUCTION
 * C++ supports three boolean operators: ! (NOT), && (AND), and || (OR). 
 * You can also use the alternative versions not, and, and or.
 *
 * PRECEDENCE
 * The three boolean operators each have different operator precedence. 
 * As a consequence, they are evaluated in this order: ! first, && second, and finally ||. 
 * If you want to force a different ordering, you can enclose a boolean expression in parentheses (ie. ()), as the parentheses have even higher operator precedence.
 *
 * CONVERSION
 * If you use true or false in a place where a number is expected, they will be converted to 1 and 0 respectively. 
 * If you use a number in a Boolean operation, everything except 0 is treated as true - even negative values.
 *
 * !true && 0.0   // => false
 * true + true + false // => 2
 */

// eat_ghost returns a boolean value if Pac-Man is able to eat the ghost.
// The function should return true only if Pac-Man has a power pellet active
// and is touching a ghost.
bool can_eat_ghost(bool power_pellet_active, bool touching_ghost) {
    // TODO: Please implement the can_eat_ghost function
    return power_pellet_active && touching_ghost;
}

// score returns a boolean value if Pac-Man scored.
// The function should return true if Pac-Man is touching a power pellet or a
// dot.
bool scored(bool touching_power_pellet, bool touching_dot) {
    // TODO: Please implement the scored function
    return touching_power_pellet || touching_dot;
}

// lost returns a boolean value if Pac-Man loses.
// The function should return true if Pac-Man is touching a ghost and
// does not have a power pellet active.
bool lost(bool power_pellet_active, bool touching_ghost) {
    // TODO: Please implement the lost function
    return !power_pellet_active && touching_ghost;
}

// won returns a boolean value if Pac-Man wins.
// The function should return true if Pac-Man
// has eaten all of the dots and has not lost
bool won(bool has_eaten_all_dots, bool power_pellet_active,
         bool touching_ghost) {
    // TODO: Please implement the won function
    return has_eaten_all_dots && !(lost(power_pellet_active, touching_ghost));
}
