/*
 * You know how sometimes you write the the same word twice in a sentence, 
 * but then don't notice that it happened? For example, you've been distracted for a second. 
 * Did you notice that "the" is doubled in the first sentence of this description?
 *
 * As as aS you can see, it's not easy to spot those errors, 
 * especially if words differ in case, like "as" at the beginning of this sentence.
 * Write a function that counts the number of sections repeating the same word (case insensitive). 
 * The occurence of two or more equal words next after each other counts as one.
 *
 * Examples
 * "dog cat"                  -->  0
 * "dog DOG cat"              -->  1
 * "apple dog cat"            -->  0
 * "pineapple apple dog cat"  -->  0
 * "apple apple dog cat"      -->  1
 * "apple dog apple dog cat"  -->  0
 * "dog dog DOG dog dog dog"  -->  1
 * "dog dog dog dog cat cat"  -->  2
 * "cat cat dog dog cat cat"  -->  3
 */
fn count_adjacent_pairs(search_string: &str) -> usize {
    let lowercased = search_string.to_lowercase();
    let words = lowercased.split_whitespace().collect::<Vec<_>>();

    let mut count = 0;
    let mut prev_word = ""; // Initially, prev_word is a string literal, which is naturally a &'static str
    let mut in_sequence = false;

    for word in &words { // word is of type &&str because it's a reference to the items of the vector
        if *word == prev_word { // Dereference word to match the type of prev_word
            if !in_sequence {
                in_sequence = true;
                count += 1;
            }
        } else {
            in_sequence = false;
        }
        prev_word = word; // Here word is a &&str so dereference it once to match &str
    }

    count
}
