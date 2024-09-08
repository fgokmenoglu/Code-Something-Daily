#include <cmath>

/* Task Description:
 * For this kata, you are given three points (x1,y1,z1), (x2,y2,z2), and (x3,y3,z3)
 * that lie on a straight line in 3-dimensional space. You have to figure out
 * which point lies in between the other two.
 *
 * Your function should return 1, 2, or 3 to indicate which point is the in-between one.
 */

unsigned middle_point(double x1, double y1, double z1,
                      double x2, double y2, double z2,
                      double x3, double y3, double z3)
{
    // Calculate the distances between each pair of points
    double d12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    double d23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2) + pow(z3 - z2, 2));
    double d31 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2) + pow(z1 - z3, 2));

    // Find the maximum distance
    double max_distance = std::max({d12, d23, d31});

    // Determine which point is in the middle
    if (max_distance == d12) return 3;
    if (max_distance == d23) return 1;
    return 2;
}
