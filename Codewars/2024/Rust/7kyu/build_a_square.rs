/*
 * I will give you an integer. 
 * Give me back a shape that is as long and wide as the integer. 
 * The integer will be a whole number between 1 and 50.
 *
 * Example
 * n = 3, so I expect a 3x3 square back just like below as a string:
 * +++
 * +++
 * +++
 */
fn generate_shape(n: i32) -> String {
    // Create a string that contains n '+' characters
    let line = "+".repeat(n as usize);

    // Repeat the line n times, separated by newlines
    let shape = line + "\n";
    shape.repeat(n as usize).trim_end().to_string()
}
