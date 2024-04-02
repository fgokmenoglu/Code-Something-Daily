/*
 * Write a method that takes an array of consecutive (increasing) letters 
 * as input and that returns the missing letter in the array.
 *
 * You will always get an valid array. And it will be always exactly one letter be missing. The length of the array will always be at least 2.
 * The array will always contain letters in only one case.
 * (Use the English alphabet with 26 letters!)
 *
 * Example:
 * ['a','b','c','d','f'] -> 'e'
 * ['O','Q','R','S'] -> 'P'
 */
fn find_missing_letter(chars: &[char]) -> char {
    // Iterate through the slice except the last character
    for i in 0..chars.len() - 1 {
        // Compare the ASCII value of the current character and the next character
        if chars[i] as u8 + 1 != chars[i + 1] as u8 {
            // If they are not consecutive, the missing letter is between them
            return (chars[i] as u8 + 1) as char;
        }
    }
    panic!("invalid argument");
}
