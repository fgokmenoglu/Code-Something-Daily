/*
 * We have the number 12385. We want to know the value of the closest cube but higher than 12385. The answer will be 13824.
 * Now, another case. We have the number 1245678. We want to know the 5th power, closest and higher than that number. The value will be 1419857.
 *
 * We need a function find_next_power, that receives two arguments, a value val, and the exponent of the power, pow_, and outputs the value that we want to find.
 *
 * The value, val will be always a positive integer.
 * The power, pow_, always higher than 1.
 */
#include <cmath>

unsigned long findNextPower(unsigned int val, unsigned int pow) {
    // Increment val by 1 to ensure we are looking for > val
    double incrementedVal = val + 1;

    // Compute the pow-th root of incrementedVal
    double root = std::pow(incrementedVal, 1.0 / pow);

    // Start searching from the ceiling of this root
    unsigned long x = static_cast<unsigned long>(std::ceil(root));
    
    // Return x^pow which is the smallest number such that x^pow > val
    return static_cast<unsigned long>(std::pow(x, pow));
}
