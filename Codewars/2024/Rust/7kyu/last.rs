/*
 * Find the last element of the given argument(s).
 *
 * Examples
 * last(&[1, 2, 3, 4])     // =>  4
 * last(&['x', 'y', 'z'])  // => 'z'
 */
fn last<T: Clone>(slice: &[T]) -> Option<T> {
    if slice.is_empty() {
        None
    } else {
        Some(slice.last().unwrap().clone())
    }
}
