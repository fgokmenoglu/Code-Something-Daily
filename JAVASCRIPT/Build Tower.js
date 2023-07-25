/*
Build Tower
Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors. A tower block is represented with "*" character.

For example, a tower with 3 floors looks like this:

[
  "  *  ",
  " *** ", 
  "*****"
]
And a tower with 6 floors looks like this:

[
  "     *     ", 
  "    ***    ", 
  "   *****   ", 
  "  *******  ", 
  " ********* ", 
  "***********"
]
*/
function towerBuilder(nFloors) {
  result = [];
  temp = "";
  
  for (let i = 0; i < nFloors; i++) {
    temp = ' '.repeat(nFloors - i - 1) + '*'.repeat(2 * i + 1) + ' '.repeat(nFloors - i - 1);
    result.push(temp);  
  }  
  
  return result;
}
