/*
 * Define a method hello that returns "Hello, Name!" to a given name, or says Hello, World! if name is not given (or passed as an empty String).
 * 
 * Assuming that name is a String and it checks for user typos to return a name with a first capital letter (Xxxx).
 * 
 * Examples:
 * 
 * With `name` = "john"  => return "Hello, John!"
 * With `name` = "aliCE" => return "Hello, Alice!"
 * With `name` not given or `name` = "" => return "Hello, World!"
 */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *hello(const char *name) {
  char *str = malloc(100);
  strcpy(str, "Hello, ");
  int len = strlen(name);
  if (len)
  {
    strcat(str, name);
    str[7] = toupper(str[7]);
    for (int i = 1; i < len; i++)
      str[i+7] = tolower(str[i+7]);
    strcat(str, "!");
  }
  else strcat(str, "World!");
  return str;
}
