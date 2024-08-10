#include <vector>
using namespace std;

/* Task Description:
 * You are given an unsorted array containing all the integers
 * from 0 to 100 inclusively. However, one number is missing.
 * Write a function to find and return this number.
 * What are the time and space complexities of your solution?
 */

int missingNo(vector<int>& arr) {
    int n = 100;  // The expected last number in the sequence
    int expectedSum = (n * (n + 1)) / 2;  // Sum of integers from 0 to 100
    int actualSum = 0;
    
    for (int num : arr) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}
