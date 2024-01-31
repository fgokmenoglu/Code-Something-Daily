/*
 * INTRODUCTION
 * So far we have mostly handled numbers and strings. 
 * To model the real world, we might want a limited number of values that a variable can take on. 
 * You might want a dedicated type with a few distinct values with distinct names.
 * You could use integers to encode those values, but you would have to use extra code to check if there is an invalid value coming from the system for the material. 
 * The meaning of those magic numbers is difficult to trace over the source code and they are prone to mix-ups. 
 * Enumerations can be used to encourage expressive code and to restrict unintentional comparison mistakes.
 * The specific term for this kind of enumeration is scoped enumeration. 
 *
 * USAGE
 * The snippet below shows how to write a DeckMaterial enumeration. Note the enum class keyword and the ; at the end of the definition:
 *
 * enum class DeckMaterial {
 *   maple,
 *   bamboo,
 *   plastic
 * };
 *
 * Now, look at a pricing function in the skate shop and take note of the scope resolution operator (::) specifying an enumerator from the enumeration:
 *
 * double deck_price(double base_price, DeckMaterial material) {
 *   if(material == DeckMaterial::plastic) {
 *     return base_price * 0.9;
 *    }
 * return base_price * 1.3;
 * }
 *
 * NOTES
 * You might be thinking that with a name like scoped, there would also be unscoped enumerations -- and you would be correct. 
 * Unscoped enumerations are becoming less popular because they all share the same global namespace. 
 * Because of the sharing, you could not have two unscoped enumerations with the same enumerators.
 * Also, unscoped enumerations implicitly convert to integers.
 * If you want to convert scoped enumerations to integers you can use static_cast<int>.
 *
 * EXTRA
 * Switch Statements
 * Like other languages, C++ also provides a switch statement. 
 * Switch statements are a shorter way to write long if ... else if statements. 
 * To make a switch, we start by using the keyword switch followed by an integer. 
 * We then declare each one of the conditions with the case keyword. 
 * We can also declare a default case, that will run when none of the previous case conditions matched. 
 * Each case should end with a break (or a return) statement.
 * One important thing about the switch construct is that the code will continue to execute until it is stopped by a break (or a return) statement. 
 * This can lead to unexpected behavior.
 * The main use case for this continued execution feature is a statement that has several labels. 
 * Multiple switch results can map to the same piece of code to be executed. 
 */
namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove
};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus posterStatus, AccountStatus viewerStatus) {
    if (posterStatus == AccountStatus::troll && viewerStatus != AccountStatus::troll)
        return false;
    
    if (posterStatus != AccountStatus::troll && viewerStatus == AccountStatus::troll)
        return false;
    
    return true; // none is a troll, so all is good
}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus accountStatus) {
    switch (accountStatus) {
        case AccountStatus::guest:
            if (action == Action::read)
                return true;
            
            return false;
        case AccountStatus::user:
        case AccountStatus::troll:
            if (action == Action::read || action == Action::write)
                return true;

            return false;
        default: // AccountStatus::mod
            return true;
    }
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus player1Status, AccountStatus player2Status) {
    if (player1Status == AccountStatus::guest || player2Status == AccountStatus::guest)
        return false;

    if (player1Status == AccountStatus::troll && player2Status != AccountStatus::troll)
        return false;
    
    if (player1Status != AccountStatus::troll && player2Status == AccountStatus::troll)
        return false;
    
    return true; // none is a guest or troll, so all is good    
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority (AccountStatus player1Status, AccountStatus player2Status) {
    return static_cast<int>(player1Status) > static_cast<int>(player2Status);
}

}  // namespace hellmath
