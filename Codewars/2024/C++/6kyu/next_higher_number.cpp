/**
 * @brief Finds the next higher integer with the same number of '1' bits.
 *
 * This function takes an integer input and returns the next higher integer
 * that has the same number of '1' bits in its binary representation.
 *
 * @param value The input integer (1 <= value <= 1<<30)
 * @return int The next higher integer with the same number of '1' bits
 *
 * @note The input is always an int between 1 and 1<<30 (possibly inclusive).
 * @note No bad cases or special tricks are considered.
 *
 * @example
 * nextHigher(129) returns 130 (10000001 => 10000010)
 * nextHigher(127) returns 191 (01111111 => 10111111)
 * nextHigher(1) returns 2 (01 => 10)
 * nextHigher(323423) returns 323439 (1001110111101011111 => 1001110111101101111)
 */
int nextHigher(int value)
{
    // Find the rightmost set bit
    int rightOne = value & -value;
    
    // Add this to the original number
    int nextHigherPattern = value + rightOne;
    
    // Get the pattern that needs to be zeroed
    int rightOnesPattern = value ^ nextHigherPattern;
    
    // Divide by 4 to move bits over to the right
    rightOnesPattern = (rightOnesPattern)/rightOne;
    
    // Get rid of the trailing zeros
    rightOnesPattern >>= 2;
    
    // Add the right ones pattern back
    int result = nextHigherPattern | rightOnesPattern;
    
    return result;
}
