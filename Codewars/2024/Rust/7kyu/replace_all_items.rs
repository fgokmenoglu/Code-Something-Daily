/*
 * Write function replaceAll that will replace all occurrences of an item with another.
 *
 * Example: replaceAll [1,2,2] 1 2 -> in list [1,2,2] we replace 1 with 2 to get new list [2,2,2]
 */
fn replace_all<T: PartialEq + Copy>(xs: &[T], find: T, replace: T) -> Vec<T> {
    xs.iter()
      .map(|&x| if x == find { replace } else { x })
      .collect()
}
