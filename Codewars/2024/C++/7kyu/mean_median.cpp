/*
 * Your goal is to implement the method meanVsMedian 
 * which accepts an odd-length array of integers and returns one of the following:
 *
 * 'mean' - in case mean value is larger than median value
 * 'median' - in case median value is larger than mean value
 * 'same' - in case both mean and median share the same value
 * 
 * Array will always be valid (odd-length >= 3)
 */
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate
#include <string>

std::string meanVsMedian(std::vector<int> numbers) {
    // Calculate the mean
    double mean = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    
    // Calculate the median
    std::sort(numbers.begin(), numbers.end());
    double median = numbers[numbers.size() / 2];

    // ALTERNATIVE for calculating the median
    std::nth_element(numbers.begin(),numbers.begin()+numbers.size()/2,numbers.end());
    double  median = numbers[numbers.size()/2];  
    
    // Compare mean and median and return the appropriate string
    if (mean > median) {
        return "mean";
    } else if (median > mean) {
        return "median";
    } else {
        return "same";
    }
}
