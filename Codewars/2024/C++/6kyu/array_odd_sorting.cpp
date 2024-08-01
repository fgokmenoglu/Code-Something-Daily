#include <vector>
#include <algorithm>
#include <iterator>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        /* Task:
        * You will be given an array of numbers. You have to sort the odd numbers in
        * ascending order while leaving the even numbers at their original positions.
        *
        * Examples:
        * [7, 1]  =>  [1, 7]
        * [5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
        * [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]
        */

        std::vector<int> oddNumbers;
        
        // Extract odd numbers
        std::copy_if(array.begin(), array.end(), std::back_inserter(oddNumbers),
                     [](int n) { return n % 2 != 0; });
        
        // Sort odd numbers
        std::sort(oddNumbers.begin(), oddNumbers.end());
        
        // Replace odd numbers in original array
        std::transform(array.begin(), array.end(), oddNumbers.begin(), array.begin(),
                       [](int n, int odd) { return n % 2 != 0 ? odd : n; });
        
        return array;
    }
};
