/*
 * In this Kata, you will be given a multi-dimensional array containing 2 or more sub-arrays of integers. 
 * Your task is to find the maximum product that can be formed by taking any one element from each sub-array.
 * 
 * Examples:
 * solve( [[1, 2],[3, 4]] ) = 8. The max product is given by 2 * 4
 * solve( [[10,-15],[-1,-3]] ) = 45, given by (-15) * (-3)
 * solve( [[1,-1],[2,3],[10,-100]] ) = 300, given by (-1) * 3 * (-100)
 */
fn solve(vecs: &[Vec<i32>]) -> i32 {
    // Start with the first sub-array
    let mut max_products = vecs[0].clone();

    // Iterate through the remaining sub-arrays
    for sub_array in vecs.iter().skip(1) {
        let mut new_products = Vec::new();

        // Calculate all possible products with the current sub-array
        for &current_num in sub_array {
            for &prev_product in &max_products {
                new_products.push(current_num * prev_product);
            }
        }

        // Update max_products with the new products
        max_products = new_products;
    }

    // Return the maximum product
    *max_products.iter().max().unwrap()
}
