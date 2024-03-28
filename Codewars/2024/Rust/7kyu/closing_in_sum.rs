/*
 * Create a function that returns the sum of the digits formed from the first and last digits, 
 * all the way to the center of the number.
 * 
 * Worked Example
 * 2520 ➞ 72
 * 
 * The first and last digits are 2 and 0.
 * 2 and 0 form 20.
 * The second digit is 5 and the second to last digit is 2.
 * 5 and 2 form 52.
 * 20 + 52 = 72
 */
fn closing_in_sum(n: u64) -> u32 {
    let digits: Vec<_> = n.to_string().chars().collect();
    let mut sum = 0;

    let mut i = 0;
    let mut j = digits.len() - 1;

    while i <= j {
        let mut num_str = String::new();
        num_str.push(digits[i]);

        // Add the digit from the end if i is not equal to j
        if i != j {
            num_str.push(digits[j]);
        }

        sum += num_str.parse::<u32>().unwrap();

        i += 1;
        j -= 1;
    }

    sum
}
