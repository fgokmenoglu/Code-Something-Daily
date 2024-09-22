/**
 * @brief Counts the number of set bits (1s) in the binary representation of a number
 *
 * This function takes an unsigned integer as input and returns the count of bits
 * that are equal to one in its binary representation.
 *
 * @param n The non-negative integer to analyze
 * @return unsigned int The count of set bits (1s) in the binary representation of n
 */
unsigned int countBits(unsigned long long n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
