/*
 * Find the last element of the given argument(s).
 *
 * Examples
 * last(&[1, 2, 3, 4])     // =>  4
 * last(&['x', 'y', 'z'])  // => 'z'
 */
fn last<T: Clone>(slice: &[T]) -> T {
    slice.last().unwrap().clone()
}

// ALTERNATIVE
fn last<T: Clone>(slice: &[T]) -> T {
  let l = slice.last();
    
  match l {
    None => panic!("empty"),
    Some(x) => x.clone(),
  }
}
