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
#include <vector>

using namespace std;

vector<int> arrayLeaders(const vector<int>& numbers) {
    vector<int> leaders;
    int size = numbers.size();
    int rightSum = 0;
    
    // Iterate from right to left
    for (int i = size - 1; i >= 0; i--) {
        // If the current number is greater than the sum of elements to its right
        if (numbers[i] > rightSum) {
            leaders.push_back(numbers[i]);
        }
        
        // Add the current number to the right sum for the next iteration
        rightSum += numbers[i];
    }
    
    // Reverse the leaders vector to maintain the original order
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
}
