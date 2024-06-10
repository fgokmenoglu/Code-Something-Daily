/*
 * Given a starting list/array of data, it could make some statistical sense to know how much each value differs from the average.
 * If for example during a week of work you have collected 55,95,62,36,48 contacts for your business, 
 * it might be interesting to know the total (296), the average (59.2), 
 * but also how much you moved away from the average each single day.
 *
 * For example on the first day you did something less than the said average (55, meaning -4.2 compared to the average), 
 * much more in the second day (95, 35.8 more than the average and so on).
 *
 * The resulting list/array of differences starting from [55, 95, 62, 36, 48] is thus [4.2, -35.8, -2.8, 23.2, 11.2].
 *
 * Assuming you will only get valid inputs (ie: only arrays/lists with numbers), 
 * create a function to do that, rounding each difference to the second decimal digit
 */
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

std::vector<double> distancesFromAverage(const std::vector<int>& input) {
    // Calculate the total sum of the elements
    double total = std::accumulate(input.begin(), input.end(), 0);
    
    // Calculate the average
    double average = total / input.size();
    
    // Create a vector to hold the differences
    std::vector<double> differences;
    differences.reserve(input.size());
    
    // Calculate the differences from the average
    for(int value : input) {
        double difference = average - static_cast<double>(value);
        // Round to two decimal places
        difference = std::round(difference * 100.0) / 100.0;
        differences.push_back(difference);
    }
    
    return differences;
}
