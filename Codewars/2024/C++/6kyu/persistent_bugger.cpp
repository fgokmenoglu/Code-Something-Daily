/**
 * @brief Calculates the multiplicative persistence of a positive number.
 *
 * Multiplicative persistence is the number of times you must multiply the 
 * digits in a number until you reach a single digit.
 *
 * @param n A positive number to calculate the multiplicative persistence for.
 * @return The multiplicative persistence of the input number.
 *
 * @note The function assumes the input is a positive number.
 *
 * @example
 * persistence(39) returns 3 (3*9 = 27, 2*7 = 14, 1*4 = 4)
 * persistence(999) returns 4 (9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, 1*2 = 2)
 * persistence(4) returns 0 (4 is already a single-digit number)
 */
int persistence(long long n) {
    int count = 0;
    
    while (n >= 10) {
        long long product = 1;
        
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        
        n = product;
        count++;
    }
    
    return count;
}
