/*
 * You are given a float (single precision) which means, 
 * that 32 bit are used to hold a value.
 *
 * Return the number an integer would hold with the same bit arrangement
 *
 * 10.0 (f32) == 01000001001000000000000000000000 (binary)
 * convert_to_i32(10.0) returns 1092616192 (i32)
 */
// return binary representation as i32
pub fn convert_to_i32(f: f32) -> i32 {
    // Convert the float to its bit representation as u32
    let bits = f.to_bits();
    
    // Transmute the bits to i32
    bits as i32
}
