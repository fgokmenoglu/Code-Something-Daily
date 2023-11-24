/*
 * Scenario
 * You're saying good-bye your best friend , See you next happy year .
 * 
 * Happy Year is the year with only distinct digits , (e.g) 2018
 * 
 * Task
 * Given a year, Find The next happy year or The closest year You'll see your best friend!alt!alt
 * 
 * Notes
 * Year Of Course always Positive .
 * Have no fear , It is guaranteed that the answer exists .
 * It's not necessary that the year passed to the function is Happy one .
 * Input Year with in range (1000  ≤  y  ≤  9000)
 */
bool checkForUniqueDigits (unsigned short int temp) {
  bool seen[10] = {false};
    
  while (temp > 0) {
    if (seen[temp % 10])
      return false;

    seen[temp % 10] = true;
    temp /= 10;
  }
  
  return true;;
}

unsigned short int nextHappyYear (unsigned short int year) {
  unsigned short int output = year;
  unsigned short int temp = 0;
  
  while (true) {
    output +=1;
    
    if (checkForUniqueDigits(output) == true)
      break;
  }
  
  return output; 
}

// ALTERNATIVE
#include <set>
unsigned short int nextHappyYear (unsigned short int year) {
  while (year++) {
    std::set<int> s;
    
    s.insert(year / 1000);
    s.insert(year / 100 % 10);
    s.insert(year / 10 % 10);
    s.insert(year % 10);
    
    if (s.size() == 4)
      return year;
  }
}
