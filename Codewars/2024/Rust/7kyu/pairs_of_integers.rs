/*
 * Implement a function that receives two integers m and n 
 * and generates a sorted list of pairs (a, b) such that m <= a <= b <= n.
 * The input m will always be smaller than or equal to n (e.g., m <= n)
 *
 * Example
 * m = 2
 * n = 4
 * result = [(2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (4, 4)]
 */
fn generate_pairs(m: i16, n: i16) -> Vec<(i16, i16)> {
    let mut result = Vec::new();  // Initialize an empty vector to store the pairs

    for a in m..=n {  // Loop from m to n (inclusive) for a
        for b in a..=n {  // Loop from a to n (inclusive) for b
            result.push((a, b));  // Add the pair (a, b) to the result vector
        }
    }

    result  // Return the result vector
}
