/*
 * You want to create secret messages.
 * Here are the conditions:
 * Your message is a string containing space separated words.
 * You need to encrypt each word in the message using the following rules:
 * The first letter must be converted to its ASCII code.
 * The second letter must be switched with the last letter
 * Keepin' it simple: There are no special characters in the input.
 *
 * Examples:
 * encrypt_this("Hello") == "72olle"
 * encrypt_this("good") == "103doo"
 * encrypt_this("hello world") == "104olle 119drlo"
 */
fn encrypt_this(text: &str) -> String {
    // Split the input text into words
    text.split_whitespace().map(|word| {
        // Convert the first character to its ASCII value
        let mut chars: Vec<char> = word.chars().collect();
        if chars.is_empty() {
            return String::new();
        }

        // Get ASCII of the first character and init the result with this ASCII number
        let first_ascii = chars[0] as u32;
        let mut encrypted_word = first_ascii.to_string();

        if chars.len() > 2 {
            // Calculate the last index once before borrowing `chars` mutably
            let last_index = chars.len() - 1;
            // Swap the second and last characters
            chars.swap(1, last_index);
        }

        // Append the rest of the characters (if any) after the first one
        if chars.len() > 1 {
            encrypted_word.push_str(&chars[1..].iter().collect::<String>());
        }

        encrypted_word
    })
    .collect::<Vec<String>>()
    .join(" ")
}

// ALTERNATIVE
fn encrypt_this(text: &str) -> String {
    text.split_ascii_whitespace()
        .map(|s| {
            let mut chars: Vec<_> = s.chars().collect();
            let ascii = chars.remove(0);
            if !chars.is_empty() {chars.swap(0, s.len() - 2)}
            format!("{}{}", (ascii as u32).to_string(), chars.into_iter().collect::<String>())
        })
        .collect::<Vec<_>>()
        .join(" ")
}
