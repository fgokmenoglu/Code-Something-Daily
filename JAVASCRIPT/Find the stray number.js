/*
 * You are given an odd-length array of integers, in which all of them are the same, except for one single number.
 *
 * Complete the method which accepts such an array, and returns that single different number.
 *
 * The input array will always be valid! (odd-length >= 3)
 *
 * Examples
 * [1, 1, 2] ==> 2
 * [17, 17, 3, 17, 17, 17, 17] ==> 3
 */
function stray(numbers) {
  unique_numbers = new Set(numbers);
  // console.log(unique_numbers.values().next().value);
  [first, second] = unique_numbers;
  // console.log(first);
  // console.log(second);
  first_count = numbers.filter(i => i == first).length;
  
  return first_count == 1 ? first : second;
}

// ALTERNATIVE USING VARIOUS ARRAY METHODS
const stray = numbers => numbers.find(num => numbers.indexOf(num) === numbers.lastIndexOf(num));
