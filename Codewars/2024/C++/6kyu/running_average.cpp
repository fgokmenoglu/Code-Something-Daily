/*
 * Create a function runningAverage() that returns a callable function object. 
 * Update the series with each given value and calculate the current average.
 *
 * rAvg = runningAverage();
 * rAvg(10) = 10.0;
 * rAvg(11) = 10.5;
 * rAvg(12) = 11;
 */
#include <cmath>

auto runningAverage() {
    int count = 0;
    double sum = 0.0;

    return [count, sum](double value) mutable -> double {
        count++;
        sum += value;
        return std::round((sum / count) * 100.0) / 100.0;
    };
}
