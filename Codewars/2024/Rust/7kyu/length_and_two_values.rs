/*
 * Given an integer n and two other values, build an array of size n filled with these two values alternating.
 * 
 * Examples
 * 5, true, false     -->  [true, false, true, false, true]
 * 10, "blue", "red"  -->  ["blue", "red", "blue", "red", "blue", "red", "blue", "red", "blue", "red"]
 * 0, "one", "two"    -->  []
 */
fn alternate<'a>(n: usize, first_value: &'a str, second_value: &'a str) -> Vec<&'a str> {
    let mut result = Vec::with_capacity(n);
    for i in 0..n {
        if i % 2 == 0 {
            result.push(first_value);
        } else {
            result.push(second_value);
        }
    }
    result
}

// ALTERNATIVE
fn alternate<'a>(n: usize, v1: &'a str, v2: &'a str) -> Vec<&'a str> {
    [v1, v2].iter().cycle().copied().take(n).collect()
}
