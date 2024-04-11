/*
 * Introduction
 * Digital Cypher assigns to each letter of the alphabet unique number. For example:
 * 
 *  a  b  c  d  e  f  g  h  i  j  k  l  m
 *  1  2  3  4  5  6  7  8  9 10 11 12 13
 *  n  o  p  q  r  s  t  u  v  w  x  y  z
 * 14 15 16 17 18 19 20 21 22 23 24 25 26
 * Instead of letters in encrypted word we write the corresponding number, eg. The word scout:
 * 
 *  s  c  o  u  t
 * 19  3 15 21 20
 * Then we add to each obtained digit consecutive digits from the key. For example. In case of key equal to 1939 :
 * 
 *    s  c  o  u  t
 *   19  3 15 21 20
 *  + 1  9  3  9  1
 *  ---------------
 *   20 12 18 30 21
 *   
 *    m  a  s  t  e  r  p  i  e  c  e
 *   13  1 19 20  5 18 16  9  5  3  5
 * +  1  9  3  9  1  9  3  9  1  9  3
 *   --------------------------------
 *   14 10 22 29  6 27 19 18  6  12 8
 * Task
 * Write a function that accepts str string and key number and returns an array of integers representing encoded str.
 * 
 * Input / Output
 * The str input string consists of lowercase characters only.
 * The key input number is a positive integer.
 * 
 * Example
 * Encode("scout",1939);  ==>  [ 20, 12, 18, 30, 21]
 * Encode("masterpiece",1939);  ==>  [ 14, 10, 22, 29, 6, 27, 19, 18, 6, 12, 8]
 */
fn encode(msg: String, key: i32) -> Vec<i32> {
    // Convert key into a vector of digits
    let mut key_digits = Vec::new();
    let mut temp_key = key;
    
    while temp_key > 0 {
        key_digits.push(temp_key % 10);
        temp_key /= 10;
    }
    
    key_digits.reverse();

    // Encode each character
    msg.chars()
       .enumerate()
       .map(|(i, c)| {
           // Convert character to number (assuming 'a' is 1, 'b' is 2, etc.)
           let char_num = c as i32 - 'a' as i32 + 1;
           // Add the corresponding key digit, cycling through the key
           char_num + key_digits[i % key_digits.len()]
       })
       .collect()
}

// ALTERNATIVE
fn encode(msg: String, n: i32) -> Vec<i32> {
    msg.chars()
        .zip(n.to_string().chars().cycle())
        .map(|(a, b)| a as i32 + b as i32 - 'a' as i32 - '1' as i32 + 2)
        .collect()
}
