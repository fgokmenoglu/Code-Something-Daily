/*
Task
You are given a string representing a number in binary. Your task is to delete all the unset bits in this string and return the corresponding number (after keeping only the '1's).

In practice, you should implement this function:

function eliminateUnsetBits(number);
Examples
eliminateUnsetBits("11010101010101") ->  255 (= 11111111)
eliminateUnsetBits("111") ->  7
eliminateUnsetBits("1000000") -> 1
eliminateUnsetBits("000") -> 0
*/
function eliminateUnsetBits(number) {
  // console.log(number);
  number = number.replaceAll('0', '');
  // console.log(number);
  
  if (number == '')
    return 0;
    
  return parseInt(number, 2);
}
/*
|| in a variable assignment is a common way to specify a default value. 
This is because of JavaScript's falsy values. 
In JavaScript, undefined, null, empty string and 0 all evaluate to false in a boolean context.
Using || in an assignment is a way of saying "if defined, otherwise use this".

For this code,

function values(b)
    this.b = b || 0;

we can use a truth table:

b          this.b
------------------
5          5
10         10
0          0
undefined  0
null       0
''         0
*/
