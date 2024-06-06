/*
 * When provided with a String, capitalize all vowels
 *
 * For example:
 * Input : "Hello World!"
 * Output : "HEllO WOrld!"
 *
 * Note: Y is not a vowel in this kata.
 */
#include <stdio.h>
#include <ctype.h>

char* capitalize_vowels(char* string) {
    if (string == NULL) return NULL;

    // Process the string and capitalize vowels
    for (size_t i = 0; string[i] != '\0'; i++) {
        char c = string[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            string[i] = toupper(c);
        }
    }
    
    return string;
}

// ALTERNATIVE
#include <string.h>
#include <ctype.h>

char *capitalize_vowels (char *string)
{
  for (char *p = string; *p; p++)
    if (strchr("aeiou", *p)) *p = toupper(*p);
  
	return string;
}
