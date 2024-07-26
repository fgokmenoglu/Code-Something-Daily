/*
 * Write a function that takes an array of unique integers 
 * and returns the minimum number of integers needed 
 * to make the values of the array consecutive 
 * from the lowest number to the highest number.
 *
 * Example
 * [4, 8, 6] --> 2
 * Because 5 and 7 need to be added to have [4, 5, 6, 7, 8]
 *
 * [-1, -5] --> 3
 * Because -2, -3, -4 need to be added to have [-5, -4, -3, -2, -1]
 * 
 * [1] --> 0
 * []  --> 0
 */
#include <stddef.h>
#include <limits.h>

int consecutive(const int arr[/* length */], size_t length)
{
    if (length <= 1) {
        return 0;
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (size_t i = 0; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int expected_range = max - min + 1;
    return expected_range - (int)length;
}
