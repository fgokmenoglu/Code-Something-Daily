/*
 * Define a function that removes duplicates 
 * from an array of non negative numbers and returns it as a result.
 * The order of the sequence has to stay the same.
 * 
 * Examples:
 * Input -> Output
 * [1, 1, 2] -> [1, 2]
 * [1, 2, 1, 1, 3, 2] -> [1, 2, 3]
 */
#include <stdlib.h>
#include <string.h>

int *distinct(const int *values, size_t count, size_t *pResultCount) {
    // Handle NULL input or empty array
    if (values == NULL || count == 0) {
        *pResultCount = 0;
        return NULL;
    }

    size_t distinctCount = 0;
    int *result = NULL;

    // First pass: count unique elements
    for (size_t i = 0; i < count; i++) {
        size_t j;
        for (j = 0; j < i; j++) {
            if (values[j] == values[i]) {
                break;
            }
        }
        if (j == i) {
            distinctCount++;
        }
    }

    // Allocate memory for the result array
    result = malloc(distinctCount * sizeof(int));
    if (result == NULL) {
        *pResultCount = 0;
        return NULL;
    }

    // Second pass: fill the result array
    size_t index = 0;
    for (size_t i = 0; i < count; i++) {
        size_t j;
        for (j = 0; j < i; j++) {
            if (values[j] == values[i]) {
                break;
            }
        }
        if (j == i) {
            result[index++] = values[i];
        }
    }

    *pResultCount = distinctCount;
    return result;
}
