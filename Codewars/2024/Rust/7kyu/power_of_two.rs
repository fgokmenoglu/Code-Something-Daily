/*
 * Complete the function power_of_two that determines if a given non-negative integer is a power of two.
 * You may assume the input is always valid.
 * Examples
 * power_of_two(0); // false
 * power_of_two(1); // true
 * power_of_two(2); // true
 * power_of_two(37); // false
 * power_of_two(64); // true
 *
 * Beware of certain edge cases - for example, 1 is a power of 2 since 2^0 = 1 and 0 is not a power of 2.
 */
fn power_of_two(x: u64) -> bool {
  x != 0 && (x & (x - 1)) == 0
}

// ALTERNATIVE
fn power_of_two(x: u64) -> bool {
    x.is_power_of_two()
}
