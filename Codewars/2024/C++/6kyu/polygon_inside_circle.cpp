/*
 * Write the following function:
 * double areaOfPolygonInsideCircle (double circleRadius , int numberOfSides)
 *
 * It should calculate the area of a regular polygon of numberOfSides, inside a circle of radius circleRadius, 
 * which passes through all the vertices of the polygon (such circle is called circumscribed circle or circumcircle).
 *
 * Input :: Output Examples
 * areaOfPolygonInsideCircle (3, 3) // returns 11.691
 * areaOfPolygonInsideCircle (5.8, 7) // returns 92.053
 * areaOfPolygonInsideCircle (4, 5) // returns 38.042
 *
 * Notes
 * If you need to use Pi in your code, use the native value of your language unless stated otherwise.
 * The answer should be a number rounded to 3 decimal places.
 */
#include <cmath>

using namespace std;

double areaOfPolygonInsideCircle(double circleRadius, int numberOfSides)
{
    const double PI = 3.14159265;
    
    // Calculate the area of the polygon
    double area = 0.5 * numberOfSides * pow(circleRadius, 2) * sin((2 * PI) / numberOfSides);
    
    // Round the result to 3 decimal places
    return round(area * 1000.0) / 1000.0;
}
