/*
Given a mixed array of number and string representations of integers, add up the non-string integers and subtract the total of the string integers.

Return as a number.
*/
function divCon(x){
  var sum_of_string_integers = 0;
  var sum_of_nonstring_integers = 0;
  
  for (var i = 0; i < x.length; i++) {
    if (typeof x[i] == 'string')
      sum_of_string_integers += Number(x[i]);
    else
      sum_of_nonstring_integers += x[i];
  }
  
  return sum_of_nonstring_integers - sum_of_string_integers;
}

// ALTERNATIVE USING REDUCE
//  return x.reduce((acc, cur) => typeof cur === 'number' ? acc + cur : acc - Number(cur), 0)
