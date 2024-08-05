#include <vector>
#include <algorithm>

/* Task Description:
 * Given an array/list [] of integers , Find the product of the k maximal numbers.
 * 
 * Notes:
 * Array/list size is at least 3 .
 * Array/list's numbers Will be mixture of positives , negatives and zeros
 * Repetition of numbers in the array/list could occur.
 * 
 * Input >> Output Examples:
 * maxProduct ({4, 3, 5}, 2) ==>  return (20)
 * 
 * Explanation:
 * Since the size (k) equal 2 , then the subsequence of size 2 whose gives product of maxima is 5 * 4 = 20 .
 */

int maxProduct(std::vector<int> numbers, int sub_size)
{
    // Sort the vector in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    // Calculate the product of the first sub_size elements
    int product = 1;
    for (int i = 0; i < sub_size; i++)
    {
        product *= numbers[i];
    }
    
    return product;
}
