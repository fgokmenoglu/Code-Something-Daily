/*
 * You are given an n by n ( square ) grid of characters, for example:
 * [['m', 'y', 'e'], 
 * ['x', 'a', 'm'], 
 * ['p', 'l', 'e']]
 * You are also given a list of integers as input, for example:
 * [1, 3, 5, 8]
 * You have to find the characters in these indexes of the grid if you think of the indexes as:
 */
fn grid_index(grid: &[Vec<char>], indices: &[usize]) -> String {
    let mut result = String::new();
    let n = grid.len(); // assuming the grid is non-empty and square

    for &index in indices {
        if index == 0 || index > n * n {
            continue; // Skip invalid indices
        }

        let adjusted_index = index - 1; // Adjusting for zero-indexing
        let row = adjusted_index / n;
        let col = adjusted_index % n;

        if let Some(char_row) = grid.get(row) {
            if let Some(&character) = char_row.get(col) {
                result.push(character);
            }
        }
    }

    result
}
