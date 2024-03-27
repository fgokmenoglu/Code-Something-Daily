/*
 * Write a function revSub which reverses all sublists where consecutive elements are even. 
 * Note that the odd numbers should remain where they are.
 *
 * Example
 * With [1,2,4,5,9] as input, we should get [1,4,2,5,9]. 
 * Here, because [2,4] is a sublist of consecutive even numbers, it should be flipped. 
 * There could be more than one sublist of even numbers, or none at all.
 * 
 * A few other examples:
 * [] -> []
 * [2,4] -> [4,2]
 * [2,4,3] -> [4,2,3]
 * [2,4,3,10,2] -> [4,2,3,2,10]
 */
fn rev_sub(xs: &[i32]) -> Vec<i32> {
    let mut result = Vec::new();
    let mut temp_even_sublist = Vec::new();

    for &x in xs {
        if x % 2 == 0 {
            // Add even numbers to the temporary sublist
            temp_even_sublist.push(x);
        } else {
            // When an odd number is encountered, reverse and append the temporary sublist to result
            if !temp_even_sublist.is_empty() {
                temp_even_sublist.reverse();
                result.extend(&temp_even_sublist);
                temp_even_sublist.clear();
            }
            // Add the odd number to the result
            result.push(x);
        }
    }

    // After the loop, check if there is a remaining even sublist
    if !temp_even_sublist.is_empty() {
        temp_even_sublist.reverse();
        result.extend(&temp_even_sublist);
    }

    result
}
