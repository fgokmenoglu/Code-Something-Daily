#include <vector>
#include <limits>
#include <algorithm>

/* Task Description:
 * Create a function that returns the sum of the two lowest positive numbers
 * given an array of minimum 4 positive integers. No floats or non-positive
 * integers will be passed.
 * 
 * For example, when an array is passed like [19, 5, 42, 2, 77], the output
 * should be 7.
 * 
 * [10, 343445353, 3453445, 3453545353453] should return 3453455.
 */

long sumTwoSmallestNumbers(std::vector<int> numbers) {
    long smallest = std::numeric_limits<long>::max();
    long secondSmallest = std::numeric_limits<long>::max();

    for (int num : numbers) {
        if (num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if (num < secondSmallest) {
            secondSmallest = num;
        }
    }

    return smallest + secondSmallest;
}
