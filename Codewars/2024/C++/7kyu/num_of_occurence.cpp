/*
 * In this kata, we want to discover a small property of numbers. 
 * We say that a number is a dd number if it contains d occurences of a digit d, (d is in [1,9]).
 *
 * Examples
 * 664444309 is a dd number, as it contains 4 occurences of the number 4
 * 30313, 122 are dd numbers as they respectively contain 3 occurences of the number 3, and (1 occurence of the number 1 AND 2 occurences of the number 2)
 * 123109, 0, 56542 are not dd numbers
 * 
 * Task
 * Your task is to implement a function called is_dd that takes a positive number 
 * (type depends on the language) and returns a boolean corresponding to 
 * whether the number is a dd number or not.
 */
#include <vector>

bool is_dd(int n) {
    std::vector<int> digit_count(10, 0);
    
    // Count occurrences of each digit
    while (n > 0) {
        int digit = n % 10;
        digit_count[digit]++;
        n /= 10;
    }
    
    // Check if any digit's count matches its value
    for (int d = 1; d <= 9; ++d) {
        if (digit_count[d] == d) {
            return true;
        }
    }
    
    return false;
}

// ALTERNATIVE
bool is_dd( int n ) {
  int d[ 10 ]{};
  do ++d[ n % 10 ]; while ( n /= 10 );
  for ( int i{ 1 }; i < 10; ++i )
    if ( d[ i ] == i ) return true;
  return false;
}
