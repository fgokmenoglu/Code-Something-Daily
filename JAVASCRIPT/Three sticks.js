/*
Imagine that you are given two sticks. You want to end up with three sticks of equal length. You are allowed to cut either or both of the sticks to accomplish this, and can throw away leftover pieces.

Write a function, maxlen, that takes the lengths of the two sticks (L1 and L2, both positive values), that will return the maximum length you can make the three sticks.
*/
function maxlen(l1, l2) {
  let max = Math.max(l1, l2);
  let min = Math.min(l1, l2);
  
  if(max / 3 > min)
    return max / 3;
  
  if(max / 2 > min)
    return min;
  
  return max / 2;
}
