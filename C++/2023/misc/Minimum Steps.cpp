/*
 * Given an array of N integers, you have to find how many times you have to add up the smallest numbers in the array until their Sum becomes greater or equal to K.
 *
 * Notes:
 * List size is at least 3.
 * All numbers will be positive.
 * Numbers could occur more than once , (Duplications may exist).
 * Threshold K will always be reachable.
 *
 * Input >> Output Example
 * minimumSteps({1, 10, 12, 9, 2, 3}, 6)  ==>  return (2)
 *
 * Explanation:
 * We add two smallest elements (1 + 2), their sum is 3 .
 * Then we add the next smallest number to it (3 + 3) , so the sum becomes 6 .
 * Now the result is greater or equal to 6 , Hence the output is (2) i.e (2) operations are required to do this .
 */
#include <vector>
#include <algorithm>  // For std::sort

using namespace std; 

int minimumSteps(vector<int> numbers, int K) {
    // Sort the numbers in ascending order
    std::sort(numbers.begin(), numbers.end());

    int sum = 0;
    int steps = 0;

    // Iterate through the sorted numbers
    for (int num : numbers) {
        sum += num;  // Add the current number to the sum
        if (sum >= K) {
            // Once the sum is greater or equal to K, return the number of steps
            return steps;
        }
        steps++;  // Increment the steps for each addition
    }

    return steps;  // The loop will always terminate early, but this is for safety
}

// ALTERNATIVE
#include <vector>
#include <algorithm>

using namespace std; 

int minimumSteps(vector<int> numbers, int input) {
    int countStep = 0, sum = 0;

    // Sort in ascending order
    sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        sum += num;
        countStep++;
        if (sum >= input) {
            break;
        }
    }

    return countStep - 1;  // Subtract 1 because we count steps from 0
}
