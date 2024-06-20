/*
 * In this kata you will be given a sequence of the dimensions of 
 * rectangles (sequence with width and length) and circles (radius - just a number).
 *
 * Your task is to return a new sequence of dimensions, sorted ascending by area.
 *
 * For example,
 * seq = { {4.23, 6.43}, {1.23, 0}, {3.444, 0}, {1.342, 3.212} } // { rectangle, circle, circle, rectangle }
 * sort_by_area(seq) => { {1.342, 3.212}, {1.23, 0}, {4.23, 6.43}, {3.444, 0} }
 */
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

// Define a type alias for better readability
using vec_rect_circle = std::vector<std::pair<double, double>>;

// Helper function to calculate the area of a shape
double area(const std::pair<double, double>& shape) {
    if (shape.second == 0) {
        // It's a circle, shape.first is the radius
        double radius = shape.first;
        return M_PI * radius * radius;
    } else {
        // It's a rectangle, shape.first is the width and shape.second is the length
        double width = shape.first;
        double length = shape.second;
        return width * length;
    }
}

// Function to sort the shapes by their area
vec_rect_circle sort_by_area(vec_rect_circle v) {
    // Use std::sort with a custom comparator that compares the areas of the shapes
    std::sort(v.begin(), v.end(), [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
        return area(a) < area(b);
    });
    return v;
}
