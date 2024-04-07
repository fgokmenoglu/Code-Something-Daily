/*
 * Given A and B, find the result of A | (A + 1) | (A + 2)| . . | B and 
 * A & (A + 1) & (A + 2) & . . & B
 *
 * Output
 * pair<uint64_t, uint64_t> orAnd(uint64_t A, uint64_t B) == return {X, Y};
 * X is the result of bitwise (inclusive) OR of numbers from A to B inclusive and
 * Y is the result of bitwise AND of numbers from A to B, inclusive.
 *
 * Note
 * | operator represents bitwise OR. 
 * A bitwise OR takes two bit patterns of equal length and 
 * performs the logical inclusive OR operation on each pair of corresponding bits. 
 * The result in each position is 1 if the first bit is 1 or the second bit is 1 or both bits are 1; 
 * otherwise, the result is 0. [Source: Wikipedia]
 * 
 * & operator represents bitwise AND. A bitwise AND takes two equal-length binary representations and 
 * performs the logical AND operation on each pair of the corresponding bits, by multiplying them. 
 * Thus, if both bits in the compared position are 1, the bit in the resulting binary representation is 1 (1 × 1 = 1); 
 * otherwise, the result is 0 (1 × 0 = 0). [Source: Wikipedia]
 *
 * Example
 *  pair<uint64_t, uint64_t> orAnd(1,1) == {1, 1};
 *  pair<uint64_t, uint64_t> orAnd(1,3) == {3, 0};
 *  pair<uint64_t, uint64_t> orAnd(10,15) == {15, 8};
 *
 * Range: 1 ≤ A ≤ B ≤ 1018
 */
#include <utility>
#include <cstdint>

std::pair<uint64_t, uint64_t> orAnd(uint64_t A, uint64_t B) {
    if (A == B) return {A, A};

    uint64_t orResult = A, andResult = A;

    // Find the most significant bit where A and B differ
    uint64_t diffBit = 0;
    for (uint64_t bit = 1ULL << 63; bit > 0; bit >>= 1) {
        if ((A & bit) != (B & bit)) {
            diffBit = bit;
            break;
        }
    }

    // Set all less significant bits to 1 in orResult
    orResult |= diffBit - 1;

    // Calculate AND result
    for (uint64_t bit = diffBit; bit > 0; bit >>= 1) {
        if ((B & bit) != 0 && (A & bit) == 0) {
            andResult &= ~bit;
            while (bit >>= 1) {
                andResult &= ~bit;
            }
            break;
        }
    }

    // Adjust orResult to include differing bits between A and B
    orResult |= (A & B) | diffBit;

    return {orResult, andResult};
}
