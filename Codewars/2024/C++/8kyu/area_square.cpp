/*
 * Complete the function that calculates the area of the red square, 
 * when the length of the circular arc A is given as the input. 
 * Return the result rounded to two decimals.
 *
 * Note: use the π value provided in your language 
 * (Math::PI, M_PI, math.pi, etc)
 */
#include <cmath>

double square_area(double A) {
    // Step 1: Calculate the radius
    // A = 2 * π * r * (1/4)  (because it's a quarter of a circle)
    // A = π * r / 2
    // r = 2A / π
    double radius = (2 * A) / M_PI;
    
    // Step 2: Calculate the area of the square
    // Area = side_length^2 = radius^2
    double area = radius * radius;
    
    // Step 3: Round to two decimal places
    return round(area * 100) / 100;
}
