/*
 * Modify the spacify function so that it returns the given string with spaces inserted between each character.
 *
 * spacify("hello world") // returns "h e l l o   w o r l d"
 */
#include <stdlib.h>
#include <string.h>

char * spacify(const char *str_in) {
  char *output = (char *) malloc(2 * strlen(str_in) * sizeof(char));
  int index = 0;
  
  for (int i = 0; str_in[i] != '\0'; i++) {
    output[index++] = str_in[i];
    output[index++] = ' ';
  }
  
  output[index - 1] = '\0';
  
  return output;    
}
