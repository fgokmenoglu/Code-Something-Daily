#include <stddef.h>
#include <stdbool.h>

/*
 * Task Description:
 * Write a function that sums a list, but ignores any duplicated items in the list.
 *
 * For instance:
 * - For the list [3, 4, 3, 6] the function should return 10
 * - For the list [1, 10, 3, 10, 10] the function should return 4
 */

int sum_no_duplicates(size_t length, const int array[length]) {
    int sum = 0;
    
    for (size_t i = 0; i < length; i++) {
        bool is_duplicate = false;
        
        // Check if the current element is a duplicate
        for (size_t j = 0; j < length; j++) {
            if (i != j && array[i] == array[j]) {
                is_duplicate = true;
                break;
            }
        }
        
        // If not a duplicate, add to sum
        if (!is_duplicate) {
            sum += array[i];
        }
    }
    
    return sum;
}
