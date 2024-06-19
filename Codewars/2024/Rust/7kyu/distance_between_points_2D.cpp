/*
 * This series of katas will introduce you 
 * to basics of doing geometry with computers.
 * Point objects have attributes x and y.
 * Write a function calculating distance 
 * between Point a and Point b.
 */

#include <cmath> // For std::sqrt and std::pow

struct Point {
    double x;
    double y;
};

double distance_between_two_points(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}
