/*
 * Given two words and a letter, return a single word that's a combination of both words, 
 * merged at the point where the given letter first appears in each word. 
 * The returned word should have the beginning of the first word and the ending of the second, 
 * with the dividing letter in the middle. You can assume both words will contain the dividing letter.
 *
 * Examples
 * ("hello", "world", "l")       ==>  "held"
 * ("coding", "anywhere", "n")   ==>  "codinywhere"
 * ("jason", "samson", "s")      ==>  "jasamson"
 * ("wonderful", "people", "e")  ==>  "wondeople"
 */
#include <stdlib.h>
#include <string.h>

char *strings_merge(const char *s1, const char *s2, char separator) {
    // Find the position of the separator in both strings
    char *pos1 = strchr(s1, separator);
    char *pos2 = strchr(s2, separator);

    if (!pos1 || !pos2) {
        // If separator is not found in either string, return NULL
        return NULL;
    }

    // Calculate the lengths of the parts
    size_t len1 = pos1 - s1;
    size_t len2 = strlen(pos2);

    // Allocate memory for the new string (+1 for the null terminator)
    char *result = (char *)malloc(len1 + len2 + 1);
    if (!result) {
        // If memory allocation fails, return NULL
        return NULL;
    }

    // Copy the first part of s1 into result
    strncpy(result, s1, len1);
    // Copy the second part of s2 (including the separator) into result
    strcpy(result + len1, pos2);

    return result;
}
