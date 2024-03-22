/*
 * Write a function that takes an input string of lowercase letters 
 * and returns true/false depending on whether the string is in alphabetical order or not.
 *
 * Examples (input -> output)
 * "kata" -> false ('a' comes after 'k')
 * "ant" -> true (all characters are in alphabetical order)
 */
fn alphabetic(s: &str) -> bool {
    let mut chars = s.chars();
    let mut prev_char = match chars.next() {
        Some(c) => c,
        None => return true, // An empty string is technically in alphabetical order
    };

    for c in chars {
        if c < prev_char {
            return false;
        }
        prev_char = c;
    }

    true
}

