/*
 * Write a program that will calculate 
 * the number of trailing zeros 
 * in a factorial of a given number.
 */

long zeros(long n) {
    long count = 0;
    
    // Count factors of 5
    for (long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    
    return count;
}
