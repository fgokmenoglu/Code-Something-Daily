/*
 * Implement a function, multiples(m, n), 
 * which returns an array of the first m 
 * multiples of the real number n. 
 * Assume that m is a positive integer.
 */
fn multiples(m: i32, n: f64) -> Vec<f64> {
    let mut result = Vec::new();
    
    for i in 1..=m {
        result.push(n * i as f64);
    }
    
    result
}
