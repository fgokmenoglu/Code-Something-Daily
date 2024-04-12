/*
 * Round any given number to the closest 0.5 step.
 * Round up if number is as close to previous and next 0.5 steps.
 *
 * solution(4.2) = 4
 * solution(4.3) = 4.5
 * solution(4.6) = 4.5
 * solution(4.8) = 5
 */
fn solution(n: f64) -> f64 {
    // Step 1: Multiply by 2
    let scaled = n * 2.0;

    // Step 2: Round to the nearest whole number
    let rounded = scaled.round();

    // Step 3: Scale back by dividing by 2
    rounded / 2.0
}
