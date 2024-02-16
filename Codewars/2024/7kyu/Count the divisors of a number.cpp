/*
 * Count the number of divisors of a positive integer n.
 *
 * Random tests go up to n = 500000.
 * 
 * Examples (input --> output)
 * 4 --> 3 // we have 3 divisors - 1, 2 and 4
 * 5 --> 2 // we have 2 divisors - 1 and 5
 * 12 --> 6 // we have 6 divisors - 1, 2, 3, 4, 6 and 12
 * 30 --> 8 // we have 8 divisors - 1, 2, 3, 5, 6, 10, 15 and 30
 * Note you should only return a number, the count of divisors. 
 * The numbers between parentheses are shown only for you to see which numbers are counted in each case.
 */
int divisors(int n) {
  int divCnt = 1;
  
  for (int i = 1; i <= n / 2; ++i)
    if (n % i == 0)
      ++divCnt;
      
  return divCnt;
}

/*
 * There is a number after n / 2 which is a divisor: The number itself. 
 * Self-division is accounted for by instantiating the count at 1, however.
 * To qualify as a divisor, dividing by anything larger than half the original number (ie: n / 2), 
 * but smaller than the number itself (ie: n), would need to result in an integer somewhere between 1 and 2. 
 * No such number exists, by definition. So we can confidently exclude those considerations.
 */
