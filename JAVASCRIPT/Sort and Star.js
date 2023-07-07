/*
You will be given a list of strings. You must sort it alphabetically (case-sensitive, and based on the ASCII values of the chars) and then return the first value.

The returned value must be a string, and have "***" between each of its letters.

You should not remove or add elements from/to the array.
*/
function twoSort(s) {
  // console.log(s)
  s.sort();
  // console.log(s) // sort() performs the operation in place, it seems
  // console.log(s[0]) // prints 'bitcoin'
  // console.log(s[0][0]) // prints 'b'
  // console.log(s[0].length) // prints 7
  
  let result = [];
  
  for (let i = 0; i < s[0].length; i++)
    if (i == (s[0].length - 1))
      result += s[0][i];
    else
      result += s[0][i] + '***';

  return result

  // Alternative
  // return s.sort()[0].split('').join('***');
}
