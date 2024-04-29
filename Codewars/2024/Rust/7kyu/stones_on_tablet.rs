/*
 * There are some stones on Bob's table in a row, 
 * and each of them can be red, green or blue, 
 * indicated by the characters R, G, and B.
 *
 * Help Bob find the minimum number of stones he needs 
 * to remove from the table so that 
 * the stones in each pair of adjacent stones have different colors.
 * 
 * Examples:
 * "RGBRGBRGGB"   => 1
 * "RGGRGBBRGRR"  => 3
 * "RRRRGGGGBBBB" => 9
 */
fn stones_to_remove(stones: &str) -> usize {
    let mut count = 0;
    let chars: Vec<char> = stones.chars().collect();

    for i in 0..chars.len() - 1 {
        if chars[i] == chars[i + 1] {
            count += 1;
        }
    }

    count
}
