/*
 * You are given two arrays a1 and a2 of strings. Each string is composed with letters from a to z. Let x be any string in the first array and y be any string in the second array.
 * 
 * Find max(abs(length(x) − length(y)))
 * 
 * If a1 and/or a2 are empty return -1 in each language except in Haskell (F#) where you will return Nothing (None).
 * 
 * Example:
 * a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
 * a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
 * mxdiflg(a1, a2) --> 13
 * 
 * Bash note:
 * input : 2 strings with substrings separated by ,
 * output: number as a string
 */
function mxdiflg(a1, a2) {
  if (a1.length == 0 || a2.length == 0)
    return -1;
  
  const ascending1 = a1.sort((str1, str2) => str1.length - str2.length);
  // console.log(ascending1);
  const ascending2 = a2.sort((str1, str2) => str1.length - str2.length);
  // console.log(ascending2);
  
  longest1 = ascending1[ascending1.length - 1].length;
  shortest1 = ascending1[0].length;
  longest2 = ascending2[ascending2.length - 1].length;
  shortest2 = ascending2[0].length;
  
  diff1 = longest2 - shortest1;
  diff2 = longest1 - shortest2;
  
  return diff1 > diff2 ? diff1 : diff2;
}
