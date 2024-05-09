/*
 * John has invited some friends. His list is:
 * s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill";
 * 
 * Could you make a program that makes this string uppercase,
 * gives it sorted in alphabetical order by last name.
 *
 * When the last names are the same, sort them by first name. 
 * Last name and first name of a guest come in the result between parentheses separated by a comma.
 * So the result of function meeting(s) will be:
 * "(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)"
 *
 * It can happen that in two distinct families with the same family name two people have the same first name too.
 */
fn meeting(s: &str) -> String {
    // Split the string into individual guest entries
    let mut guests = s.split(';')
        .map(|entry| {
            // Split each entry into first and last names
            let parts: Vec<&str> = entry.split(':').collect();
            let first_name = parts[0].to_uppercase();
            let last_name = parts[1].to_uppercase();
            // Rearrange into the desired format
            (last_name, first_name)
        })
        .collect::<Vec<(String, String)>>();

    // Sort the guests by last name, then by first name
    guests.sort_by(|a, b| a.0.cmp(&b.0).then_with(|| a.1.cmp(&b.1)));

    // Concatenate all names into the final string
    guests.iter()
        .map(|(last_name, first_name)| format!("({}, {})", last_name, first_name))
        .collect()
}
