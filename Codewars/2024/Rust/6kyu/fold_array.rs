/*
 * In this kata you have to write a method that folds a given array of integers by the middle x-times.
 * An example says more than thousand words:
 *
 * Fold 1-times:
 * [1,2,3,4,5] -> [6,6,3]
 * Fold 2-times:
 * [1,2,3,4,5] -> [9,6]
 *
 * As you see, if the count of numbers is odd, the middle number will stay. 
 * Otherwise the fold-point is between the middle-numbers, so all numbers would be added in a way.
 * The array will always contain numbers and will never be null. 
 * The parameter runs will always be a positive integer greater than 0 and says how many runs of folding your method has to do.
 * If an array with one element is folded, it stays as the same array.
 * The input array should not be modified!
 */
fn fold_array(arr: &[i32], runs: usize) -> Vec<i32> {
    if arr.is_empty() || runs == 0 {
        return Vec::new();
    }

    let mut current = arr.to_vec();

    for _ in 0..runs {
        let len = current.len();
        let mid = len / 2;

        let mut folded = Vec::new();
        for i in 0..mid {
            folded.push(current[i] + current[len - 1 - i]);
        }

        if len % 2 != 0 {
            folded.push(current[mid]);
        }

        current = folded;
    }

    current
}
