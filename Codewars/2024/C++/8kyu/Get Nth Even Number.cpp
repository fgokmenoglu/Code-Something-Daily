/*
 * Return the Nth Even Number
 * 
 * Examples 
 * (Input --> Output)
 * 1 --> 0 (the first even number is 0)
 * 3 --> 4 (the 3rd even number is 4 (0, 2, 4))
 * 100 --> 198
 * 1298734 --> 2597466
 *
 * Notes
 * The input will not be 0.
 */
int nthEven(int n) {
  int out = 0, idx = 1;
  
  while (true) {
    out += 2;
    idx += 1;
    
    if (idx == n)
      break;
  }
  
  return out;
}
