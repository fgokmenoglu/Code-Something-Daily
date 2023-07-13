/*
Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321
*/
function descendingOrder(n){
  orig_digits = [];
  
  if (n == 0)
    return 0;
  
  while (n > 0) {
    orig_digits.push(n % 10);
    n = Math.floor(n / 10);
  }
  
  desc_digits = orig_digits.sort((a,b) => (b - a)); // can also simply use sort() for this practice
  
  return desc_digits.reduce((accum, digit) => (accum * 10) + digit, 0);
}
