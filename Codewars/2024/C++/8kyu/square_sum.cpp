#include <vector>

/**
 * @brief Calculates the sum of squares of given numbers
 *
 * This function squares each number passed into it and then
 * sums the results together.
 *
 * @param numbers A vector of integers to be squared and summed
 * @return The sum of squares of the input numbers
 */
int square_sum(const std::vector<int>& numbers)
{
    int sum = 0;
    for (int num : numbers) {
        sum += num * num;
    }
    return sum;
}
