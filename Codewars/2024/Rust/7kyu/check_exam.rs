/*
 * The first input array is the key to the correct answers to an exam, like ["a", "a", "b", "d"]. 
 * The second one contains a student's submitted answers.
 * The two arrays are not empty and are the same length. 
 * Return the score for this array of answers, 
 * giving +4 for each correct answer, 
 * -1 for each incorrect answer, 
 * and +0 for each blank answer, 
 * represented as an empty string (in C the space character is used).
 * If the score < 0, return 0.
 *
 * For example:
 * checkExam(["a", "a", "b", "b"], ["a", "c", "b", "d"]) → 6
 * checkExam(["a", "a", "c", "b"], ["a", "a", "b",  ""]) → 7
 * checkExam(["a", "a", "b", "c"], ["a", "a", "b", "c"]) → 16
 * checkExam(["b", "c", "b", "a"], ["",  "a", "a", "c"]) → 0
 */
fn check_exam(arr_a: &[&str], arr_b: &[&str]) -> i64 {
    let mut score = 0;

    for (correct, answer) in arr_a.iter().zip(arr_b.iter()) {
        if *answer == "" {
            // Do nothing if the answer is blank.
        } else if answer == correct {
            score += 4;  // Award 4 points for a correct answer.
        } else {
            score -= 1;  // Deduct 1 point for a wrong answer.
        }
    }

    // Ensure the score is not negative.
    if score < 0 {
        0
    } else {
        score
    }
}
