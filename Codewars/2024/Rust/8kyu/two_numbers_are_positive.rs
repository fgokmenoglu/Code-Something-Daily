/*
 * Task:
 * Your job is to write a function, which takes three integers a, b, and c as arguments, 
 * and returns True if exactly two of of the three integers are positive numbers (greater than zero), 
 * and False - otherwise.
 * 
 * Examples:
 * two_are_positive(2, 4, -3) == true
 * two_are_positive(-4, 6, 8) == true
 * two_are_positive(4, -6, 9) == true
 * two_are_positive(-4, 6, 0) == false
 * two_are_positive(4, 6, 10) == false
 * two_are_positive(-14, -3, -4) == false
 */
fn two_are_positive(a: i32, b: i32, c: i32) -> bool {
    let mut count = 0;

    if a > 0 {
        count += 1;
    }
    if b > 0 {
        count += 1;
    }
    if c > 0 {
        count += 1;
    }

    count == 2
}

// ALTERNATIVE
fn two_are_positive(a: i32, b: i32, c: i32) -> bool {
    [a,b,c].into_iter().filter(|&x| x>0).count()==2
}
