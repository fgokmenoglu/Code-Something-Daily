/*
 * Given a string, you have to return a string in which each character (case-sensitive) is repeated once.
 * 
 * Examples (Input -> Output):
 * "String"      -> "SSttrriinngg"
 * "Hello World" -> "HHeelllloo  WWoorrlldd"
 * "1234!_ "     -> "11223344!!__  "
 */
char *double_char (const char *string, char *doubled) {
  *doubled = '\0'; // write to doubled
  int j = 0;
  
  for (int i = 0; string[i] != '\0'; i++) {
    doubled[j++] = string[i];
    doubled[j++] = string[i];
  }
  
  doubled[j] = '\0';
  
  return doubled; // return it
}
