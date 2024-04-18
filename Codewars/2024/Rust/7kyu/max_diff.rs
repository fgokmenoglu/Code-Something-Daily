/*
 * You must implement a function that returns the difference 
 * between the largest and the smallest value in a given list/array (lst).
 * 
 * lst contains integers, that means it may contain some negative numbers
 * if lst is empty or contains a single element, return 0
 * lst is not sorted
 *
 * [1, 2, 3, 4]   //  returns 3 because 4 -   1  == 3
 * [1, 2, 3, -4]  //  returns 7 because 3 - (-4) == 7
 */
fn max_diff(numbers: &[i32]) -> i32 {
    if numbers.len() <= 1 {
        // If the list is empty or has only one element, return 0
        0
    } else {
        // Use Rust's built-in functions to find the maximum and minimum elements
        let max = numbers.iter().max().unwrap();  // Safely unwrap since we know the slice isn't empty
        let min = numbers.iter().min().unwrap();  // Safely unwrap since we know the slice isn't empty
        max - min  // Return the difference between the maximum and minimum
    }
}
