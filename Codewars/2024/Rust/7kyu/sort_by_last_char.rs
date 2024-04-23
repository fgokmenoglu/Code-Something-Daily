/*
 * Given a string of words (x), 
 * you need to return an array of the words, 
 * sorted alphabetically by the final character in each.
 * 
  * If two words have the same last letter, 
  * the returned array should show them in the order 
  * they appeared in the given string.
  * 
  * All inputs will be valid.
  */
fn sort_by_last_char(s: &str) -> Vec<String> {
    // Split the string into words and collect them into a vector of Strings
    let mut words: Vec<String> = s.split_whitespace().map(String::from).collect();
    
    // Use stable sort to maintain relative order of words with the same last character
    words.sort_by_key(|word| word.chars().last());
    
    words
}
