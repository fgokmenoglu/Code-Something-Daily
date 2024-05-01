/*
 * You will be given a string of English digits "stuck" together, like this:
 * "zeronineoneoneeighttwoseventhreesixfourtwofive"
 *
 * Your task is to split the string into separate digits:
 * "zero nine one one eight two seven three six four two five"
 *
 * More Examples
 * "three"              -->  "three"
 * "eightsix"           -->  "eight six"
 * "fivefourseven"      -->  "five four seven"
 * "ninethreesixthree"  -->  "nine three six three"
 * "fivethreefivesixthreenineonesevenoneeight"  -->  "five three five six three nine one seven one eight"
 */
fn uncollapse(digits: &str) -> String {
    // English words for each digit
    let words = vec![
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    ];

    // Initialize an empty string to store the result
    let mut result = String::new();

    // Use a mutable slice of the input string to track our position as we find matches
    let mut current_slice = digits;

    while !current_slice.is_empty() {
        let mut found = false;

        // Try to match each word with the beginning of the current slice
        for word in &words {
            if current_slice.starts_with(word) {
                // If a word matches, append it to the result with a space
                if !result.is_empty() {
                    result.push(' ');
                }
                result.push_str(word);
                // Advance the slice past this word
                current_slice = &current_slice[word.len()..];
                found = true;
                break;
            }
        }

        // If no word matches, move forward by one character to avoid infinite loops
        // This situation shouldn't occur if the input is guaranteed to be valid
        if !found {
            current_slice = &current_slice[1..];
        }
    }

    result
}

// ALTERNATIVE
use regex::Regex;
use itertools::Itertools;

fn uncollapse(digits: &str) -> String {
    Regex::new(r"zero|one|two|three|four|five|six|seven|eight|nine")
        .unwrap()
        .find_iter(digits)
        .map(|matched| matched.as_str())
        .join(" ")
}
