#include <vector>

/*
 * Description:
 * The task is to get the sum of two arrays; that is, the sum of all their elements.
 * Each array includes only integer numbers. Output is a number too.
 */

int arrayPlusArray(std::vector<int> a, std::vector<int> b) {
    int sum = 0;
    for (int num : a) sum += num;
    for (int num : b) sum += num;
    return sum;
}
