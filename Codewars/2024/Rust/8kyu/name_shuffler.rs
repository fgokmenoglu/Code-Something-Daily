/*
 * Write a function that returns a string in which 
 * firstname is swapped with last name.
 *
 * Example(Input --> Output)
 * "john McClane" --> "McClane john"
 */
fn name_shuffler(s: &str) -> String {
    let parts: Vec<&str> = s.splitn(2, ' ').collect();
    if parts.len() == 2 {
        format!("{} {}", parts[1], parts[0])
    } else {
        s.to_string()
    }
}
