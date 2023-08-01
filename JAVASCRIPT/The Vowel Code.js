/*
Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:

a -> 1
e -> 2
i -> 3
o -> 4
u -> 5
For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.

Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.

For example, decode("h3 th2r2") would return "hi there".

For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.
*/
function encode(string) {
  string = string.replaceAll('a', '1');
  string = string.replaceAll('e', '2');
  string = string.replaceAll('i', '3');
  string = string.replaceAll('o', '4');
  string = string.replaceAll('u', '5');
  
  return string;
}

function decode(string) {
  string = string.replaceAll('1', 'a');
  string = string.replaceAll('2', 'e');
  string = string.replaceAll('3', 'i');
  string = string.replaceAll('4', 'o');
  string = string.replaceAll('5', 'u');
  
  return string;
}

// ALTERNATIVE USING REGEX
// turn vowels into numbers
/*
function encode(string){
  return string.replace(/[aeiou]/g, function (x) { return '_aeiou'.indexOf(x) });
}

//turn numbers back into vowels
function decode(string){
  return string.replace(/[1-5]/g, function (x) { return '_aeiou'.charAt(x) });
}
*/

/*
The replace() method returns a new string with one, some, or all matches of a pattern replaced by a replacement. 
The pattern can be a string or a RegExp, and the replacement can be a string or a function called for each match. 
If pattern is a string, only the first occurrence will be replaced. The original string is left unchanged.
*/
