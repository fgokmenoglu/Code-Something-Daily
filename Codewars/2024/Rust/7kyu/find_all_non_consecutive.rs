/*
 * Your task is to find all the elements of an array that are non consecutive.
 * A number is non consecutive if it is not exactly one larger than the previous element in the array. 
 * The first element gets a pass and is never considered non consecutive.
 * 
 * Create a function name all_non_consecutive.
 * E.g., if we have an array [1,2,3,4,6,7,8,15,16] then 6 and 15 are non-consecutive.
 * 
 * You should return the results as an array of tuples with two values: 
 * the index of the non-consecutive number and the non-consecutive number.
 * E.g., for the above array the result should be:
 *
 * [
 *  ( 4, 6 ),
 *  ( 7, 15 )
 * ]
 *
 * If the whole array is consecutive or has one element then return an empty array.
 * The array elements will all be numbers. 
 * The numbers will also all be unique and in ascending order. 
 * The numbers could be positive and/or negetive and the gap could be larger than one.
 */
fn all_non_consecutive(arr: &[i32]) -> Vec<(usize, i32)> {
    let mut result = Vec::new();

    // Start from the second element and check each element against its predecessor
    for (i, &current) in arr.iter().enumerate().skip(1) {
        let prev = arr[i - 1];
        
        if current != prev + 1 {
            result.push((i, current));
        }
    }

    result
}
