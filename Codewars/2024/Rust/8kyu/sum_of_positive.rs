/*
 * You get an array of numbers, return the sum of all of the positives ones.
 * Example: [1,-4,7,12] => 1 + 7 + 12 = 20
 * Note: If there is nothing to sum, the sum is default to 0.
 */
fn positive_sum(slice: &[i32]) -> i32 {
    let mut sum = 0;
    
    for &number in slice {
        if number > 0 {
            sum += number;
        }
    }
    
    sum
}
