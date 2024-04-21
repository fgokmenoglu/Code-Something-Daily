/*
 * Write reverseList function that simply reverses lists.
 */
fn reverse_list(lst: &[i32]) -> Vec<i32> {
    let mut reversed = Vec::with_capacity(lst.len()); // Pre-allocate space for efficiency
    
    for &item in lst.iter().rev() {
        reversed.push(item);
    }
  
    reversed
}

// ALTERNATIVE
fn reverse_list(lst: &[i32]) -> Vec<i32> {
    lst.iter().rev().cloned().collect()
}
