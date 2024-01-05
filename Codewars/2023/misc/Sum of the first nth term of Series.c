/*
 * Task:
 * Your task is to write a function which returns the sum of following series upto nth term(parameter).
 * 
 * Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
 * Rules:
 * You need to round the answer to 2 decimal places and return it as String.
 * 
 * If the given value is 0 then it should return 0.00
 * 
 * You will only be given Natural Numbers as arguments.
 * 
 * Examples:(Input --> Output)
 * 1 --> 1 --> "1.00"
 * 2 --> 1 + 1/4 --> "1.25"
 * 5 --> 1 + 1/4 + 1/7 + 1/10 + 1/13 --> "1.57"
 */
#include <stdlib.h> // malloc()
#include <stdio.h> // snprintf()

char* series_sum(const size_t n) {
    if (n == 0) {
        char* result = (char*) malloc(5); // "0.00" plus a null terminator
        snprintf(result, 5, "0.00");
        return result;
    }

    double sum = 0.0;
    double denominator = 1.0;

    for (size_t i = 0; i < n; i++) {
        sum += 1.0 / denominator;
        denominator += 3.0;
    }

    char* result = (char*) malloc(5); // "X.YY" plus a null terminator
    snprintf(result, 5, "%.2f", sum);

    return result;
}

// ADDITIONAL INFORMATION
/*
 *  The snprintf() function is identical to the sprintf() function with the addition of the n argument, 
 * which indicates the maximum number of characters (including the ending null character) to be written 
 * to buffer.
 */
