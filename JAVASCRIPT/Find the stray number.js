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

// The find() method of Array instances returns the first element in the provided array that satisfies the provided testing function. If no values satisfy the testing function, undefined is returned.
// The indexOf() method of Array instances returns the first index at which a given element can be found in the array, or -1 if it is not present.
// The lastIndexOf() method of Array instances returns the last index at which a given element can be found in the array, or -1 if it is not present. The array is searched backwards.
