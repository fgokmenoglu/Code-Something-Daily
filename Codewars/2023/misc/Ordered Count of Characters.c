/*
 * Count the number of occurrences of each character and return it as a (list of tuples) in order of appearance. For empty output return (an empty list).
 * 
 * Consult the solution set-up for the exact data structure implementation depending on your language.
 * 
 * Example:
 * 
 * ordered_count("abracadabra", *szout);
 * 
 * // using:
 * typedef struct Character_Count_Pair {
 *     char character;
 *     size_t count;
 * } ccp;
 * 
 * // returns:
 * {{'a', 5}, {'b', 2}, {'r', 2}, {'c', 1}, {'d', 1}}
 * 
 * // assigns length:
 * szout = 5
 */
#include <stddef.h>
#include <stdlib.h>

typedef struct Character_Count_Pair {
    char character;
    size_t count;
} ccp;

ccp* ordered_count(const char *strin, size_t *szout) {
    // Create an array to store character-count pairs
    ccp *result = NULL;
    size_t resultSize = 0;

    // Iterate through the input string
    for (size_t i = 0; strin[i] != '\0'; i++) {
        char currentChar = strin[i];
        int charExists = 0;

        // Check if the current character already exists in the result array
        for (size_t j = 0; j < resultSize; j++) {
            if (result[j].character == currentChar) {
                // Character already exists, increment the count
                result[j].count++;
                charExists = 1;
                break;
            }
        }

        if (!charExists) {
            // Character doesn't exist in the result array, add a new pair
            resultSize++;
            result = (ccp *)realloc(result, resultSize * sizeof(ccp));
            result[resultSize - 1].character = currentChar;
            result[resultSize - 1].count = 1;
        }
    }

    // Assign the length to szout
    *szout = resultSize;

    return result;
}

// ALTERNATIVE
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct Character_Count_Pair {
    char character;
    size_t count;
} ccp;

ccp* ordered_count(const char *strin, size_t *szout) {
    size_t len = strlen(strin);
    ccp* result = malloc(len * sizeof(ccp));
    size_t count = 0;
    for (size_t i = 0; i < len; i++) {
        char c = strin[i];
        size_t j;
        for (j = 0; j < count; j++) {
            if (result[j].character == c) {
                result[j].count++;
                break;
            }
        }
        if (j == count) {
            result[count].character = c;
            result[count].count = 1;
            count++;
        }
    }
    *szout = count;
    return result;
}
