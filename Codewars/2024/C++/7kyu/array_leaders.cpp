/*
 * Definition
 * An element is leader if it is greater than 
 * the sum all the elements to its right side.
 * 
 * Task
 * Given an array/list [] of integers,
 * find all the LEADERS in the array.
 *
 * Notes
 * Array/list size is at least 3 .
 * Array/list's numbers will be mixture of positives, negatives and zeros
 * Repetition of numbers in the array/list could occur.
 * Returned array/list should store the leading numbers 
 * in the same order in the original array/list .
 * 
 * Input >> Output Examples
 * arrayLeaders ({1, 2, 3, 4, 0}) ==> return {4}
 * Explanation:
 * 4 is greater than the sum all the elements to its right side
 * Note : The last element 0 is equal to right sum of its elements (abstract zero).
 *
 * arrayLeaders ({16, 17, 4, 3, 5, 2}) ==> return {17, 5, 2}
 * Explanation:
 * 17 is greater than the sum all the elements to its right side
 * 5 is greater than the sum all the elements to its right side
 * Note : The last element 2 is greater than the sum of its right elements (abstract zero). 
 */
