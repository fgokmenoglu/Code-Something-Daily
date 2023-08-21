/*
Imagine that you are given two sticks. You want to end up with three sticks of equal length. You are allowed to cut either or both of the sticks to accomplish this, and can throw away leftover pieces.

Write a function, maxlen, that takes the lengths of the two sticks (L1 and L2, both positive values), that will return the maximum length you can make the three sticks.
*/
function maxlen(l1, l2) {
  if (l1 * 2 <= l2)
    return l1;
  
  if (l2 * 2 <= l1)
    return l2;
  
  return 0;
}
