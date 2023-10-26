/*
 * We want to know the index of the vowels in a given word, for example, there are two vowels in the word super (the second and fourth letters).
 * 
 * So given a string "super", we should return a list of [2, 4].
 * 
 * Some examples:
 * Mmmm  => []
 * Super => [2,4]
 * Apple => [1,5]
 * YoMama -> [1,2,4,6]
 *
 * NOTES
 * Vowels in this context refers to: a e i o u y (including upper case)
 * This is indexed from [1..n] (not zero indexed!)
 */
#include <stddef.h>
#include <stdlib.h>

int is_vowel(char c) {
    // Helper function to check if a character is a vowel
    char vowels[] = "aeiouyAEIOUY";
    for (int i = 0; vowels[i]; i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int *vowel_indices(const char *string, size_t *nb_vowels) {
    // Find the number of vowels in the input string
    size_t count = 0;
    for (size_t i = 0; string[i]; i++) {
        if (is_vowel(string[i])) {
            count++;
        }
    }

    // Allocate memory for the array
    int *result = (int *)malloc(count * sizeof(int));
    if (result == NULL) {
        *nb_vowels = 0;
        return NULL; // Memory allocation failed
    }

    // Find the indices of the vowels and store them in the array
    size_t vowel_count = 0;
    for (size_t i = 0; string[i]; i++) {
        if (is_vowel(string[i])) {
            result[vowel_count] = i + 1; // Adjust for 1-based indexing
            vowel_count++;
        }
    }

    *nb_vowels = count;
    return result;
}

// ALTERNATIVE
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int *vowel_indices (const char *string, size_t *nb_vowels) {
  int *ret = malloc(strlen(string) * sizeof(int));
  
  *nb_vowels = 0;
  
  for (const char *s = string; *s; s++)
    if (strchr("AEIOUYaeiouy", *s))
      ret[(*nb_vowels)++] = s - string + 1;
  
	return realloc (ret, *nb_vowels * sizeof(int));
}
