/*
 * A Cartesian coordinate system is a coordinate system that specifies each point uniquely in a plane by a pair of numerical coordinates, 
 * which are the signed distances to the point from two fixed perpendicular directed lines, measured in the same unit of length.
 *
 * The сoordinates of a point in the grid are written as (x,y). Each point in a coordinate system has eight neighboring points. 
 * Provided that the grid step = 1. It is necessary to write a function that takes a coordinate on the x-axis and y-axis and returns a list of all the neighboring points. 
 * Points inside your returned list need not be sorted (any order is valid).
 *
 * For Example:
 * Given x = 2 and y = 2, the function should return [(1,1),(1,2),(1,3),(2,1),(2,3),(3,1),(3,2),(3,3)];
 * Given x = 5 and y = 7, the function should return [(6,7),(6,6),(6,8),(4,7),(4,6),(4,8),(5,6),(5,8)].
 *
 * Note that the required data structure to contain the coordinates might not be the same between translations, so check the sample test cases provided.
 */
#include <vector>

using std::vector;

vector<vector<int>> cartesianNeighbor(int x, int y) {
    vector<vector<int>> neighbors;

    // Loop through the neighboring coordinates
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            // Skip the original point (0,0) offset
            if (dx == 0 && dy == 0) continue;

            neighbors.push_back({x + dx, y + dy});
        }
    }

    return neighbors;
}
