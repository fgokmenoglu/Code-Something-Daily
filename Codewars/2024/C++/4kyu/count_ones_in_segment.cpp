/*
 * Given two numbers: 'left' and 'right' (1 <= 'left' <= 'right' <= 200000000000000) 
 * return sum of all '1' occurencies in binary representations of numbers 
 * between 'left' and 'right' (including both)
 * 
 * Example:
 * countOnes 4 7 should return 8, because:
 * 4(dec) = 100(bin), which adds 1 to the result.
 * 5(dec) = 101(bin), which adds 2 to the result.
 * 6(dec) = 110(bin), which adds 2 to the result.
 * 7(dec) = 111(bin), which adds 3 to the result.
 * So finally result equals 8.
 * 
 * WARNING: Segment may contain billion elements, 
 * don't iterate through all numbers in the segment!
 */
// Function to count set bits from 0 to n
long long countSetBitsFromZeroTo(long long n) {
    if (n == 0) return 0;
    
    long long x = 0;
  
    while ((1LL << (x + 1)) <= n) {
        ++x;
    }
    
    long long till_2_pow_x_minus_1 = x * (1LL << (x - 1));
    long long msb_2_pow_x_to_n = n - (1LL << x) + 1;
    long long rest = n - (1LL << x);
    
    return till_2_pow_x_minus_1 + msb_2_pow_x_to_n + countSetBitsFromZeroTo(rest);
}

// Wrapper function to compute from left to right
long long countOnes(int left, int right) {
    return countSetBitsFromZeroTo(right) - (left > 0 ? countSetBitsFromZeroTo(left - 1) : 0);
}
