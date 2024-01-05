/*
 * Write a simple regex to validate a username. Allowed characters are:
 * 
 * lowercase letters,
 * numbers,
 * underscore
 * 
 * Length should be between 4 and 16 characters (both included).
 */
#include <stdbool.h>
#include <regex.h>
#include <stddef.h>

bool validate_username (const char *username) {
    regex_t regex;
    int value;

    const char *pattern = "^[a-z0-9_]{4,16}$";
    value = regcomp(&regex, pattern, REG_EXTENDED);
    
    if (value)
      return false;

    value = regexec(&regex, username, 0, NULL, 0);
    regfree(&regex);
  
    return value ? false : true;
}

// ALTERNATIVE
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validate_username (const char *username) {
  int len = strlen(username);
  
  if(len < 4 || len > 16)
    return false;
  
  for(int i = 0; i < len; ++i)
    if(!isdigit(username[i]) && username[i] != '_' && !islower(username[i]))
      return false;
  
	return true;
}
