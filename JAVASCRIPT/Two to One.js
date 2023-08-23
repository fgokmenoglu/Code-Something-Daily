/*
Take 2 strings s1 and s2 including only letters from a to z. Return a new sorted string, the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.

Examples:
a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
longest(a, b) -> "abcdefklmopqwxy"

a = "abcdefghijklmnopqrstuvwxyz"
longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"
*/
function longest(s1, s2) {
  // console.log(s1 + s2);
  
  function onlyUnique(value, index, array) {
    return array.indexOf(value) === index;
  }
  
  var unique_arr = (s1 + s2).split('').filter(onlyUnique);
  unique_arr.sort();
  var unique_str = unique_arr.join('');
  
  // console.log(unique_str);
  return unique_str;
}
// ALTERNATIVE
// const longest = (s1, s2) => [...new Set(s1+s2)].sort().join('')
