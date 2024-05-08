/*
 * Write a program that outputs the top n elements from a list.
 *
 * Example:
 * largest(2, [7,6,5,4,3,2,1]) => [6,7]
 */
fn largest(n: usize, xs: &[i32]) -> Vec<i32> {
    // Edge case: if n is 0, return an empty vector
    if n == 0 {
        return vec![];
    }

    // Clone the slice into a new vector so we can sort it
    let mut sorted_xs = xs.to_vec();

    // Sort the vector in ascending order
    sorted_xs.sort_unstable();

    // Take the last n elements to get the largest ones and ensure they are in ascending order
    sorted_xs.iter().skip(sorted_xs.len() - n).cloned().collect()
}
