/*
 * Write a function that takes a string and 
 * outputs a strings of 1's and 0's 
 * where vowels become 1's and non-vowels become 0's.
 *
 * All non-vowels including non alpha characters (spaces,commas etc.) should be included.
 *
 * Examples:
 * vowelOne "abceios" -- "1001110"
 * vowelOne "aeiou, abc" -- "1111100100"
 */
#include <ctype.h>

// Function to check if a character is a vowel
int is_vowel(char c) {
    c = tolower(c); // Convert to lowercase for uniformity
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to convert vowels to '1' and non-vowels to '0'
char *vowel_one(const char *input, char *output) {
    char *original_output = output; // Save the starting address of output

    while (*input) {
        if (is_vowel(*input)) {
            *output = '1';
        } else {
            *output = '0';
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
    return original_output; // Return the starting address of output
}

// ALTERNATIVE
char *vowel_one(const char *input, char *output) {
  char *r = output;
  
  while (*input) {
    *r++ = strchr("aeiouAEIOU", *input++) ? '1' : '0';
  }

  return *r = 0, output;
}
