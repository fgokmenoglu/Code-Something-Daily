/*
 * Your task is to return an output string that translates an input string s 
 * by replacing each character in s with a number representing the number of times 
 * that character occurs in s and separating each number with the sep character(s).
 *
 * Example (s, sep --> Output)
 *
 * "hello world", "-" --> "1-1-3-3-2-1-1-2-1-3-1"
 * "19999999"   , ":" --> "1:7:7:7:7:7:7:7"
 * "^^^**$"     , "x" --> "3x3x3x2x2x1"
 */
fn freq_seq(s: &str, sep: &str) -> String {
    let mut char_counts = std::collections::HashMap::new();

    // Count occurrences of each character
    for c in s.chars() {
        *char_counts.entry(c).or_insert(0) += 1;
    }

    // Map each character to its frequency and join with sep
    s.chars()
        .map(|c| char_counts[&c].to_string())
        .collect::<Vec<String>>()
        .join(sep)
}
