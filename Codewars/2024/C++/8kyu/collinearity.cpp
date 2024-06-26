/*
 * You are given two vectors starting from the origin (x=0, y=0) with coordinates (x1,y1) and (x2,y2). 
 * Your task is to find out if these vectors are collinear. 
 * Collinear vectors are vectors that lie on the same straight line. 
 * They can be directed in the same or opposite directions. 
 * One vector can be obtained from another by multiplying it by a certain number. 
 * In terms of coordinates, vectors (x1, y1) and (x2, y2) are collinear if (x1, y1) = (k*x2, k*y2), 
 * where k is any number acting as a coefficient.
 *
 * Write the function collinearity(x1, y1, x2, y2), 
 * which returns a Boolean type depending on whether the vectors are collinear or not.
 * Notes
 * All coordinates are integers with -1000 <= any coordinate <= 1000.
 * All vectors start from the origin (x=0, y=0).
 * Be careful when handling cases where x1, x2, y1, or y2 are zero to avoid division by zero errors.
 * A vector with coordinates (0, 0) is collinear to all vectors.
 * 
 * Examples
 * (1,1,1,1) ➞ true
 * (1,2,2,4) ➞ true
 * (1,1,6,1) ➞ false
 * (1,2,-1,-2) ➞ true
 * (1,2,1,-2) ➞ false
 * (4,0,11,0) ➞ true
 * (0,1,6,0) ➞ false
 * (4,4,0,4) ➞ false
 * (0,0,0,0) ➞ true
 * (0,0,1,0) ➞ true
 * (5,7,0,0) ➞ true
 */
bool collinearity(int x1, int y1, int x2, int y2) {
    // Check if both vectors are (0, 0)
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
        return true;
    }
    
    // Check if one vector is (0, 0)
    if ((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) {
        return true;
    }
    
    // Check for division by zero cases
    if (x1 == 0 && x2 == 0) {
        return true;  // Both vectors are vertical
    }
    if (y1 == 0 && y2 == 0) {
        return true;  // Both vectors are horizontal
    }
    
    // Compare ratios
    if (x1 != 0 && x2 != 0) {
        return (static_cast<double>(y1) / x1 == static_cast<double>(y2) / x2);
    } else {
        return (static_cast<double>(x1) / y1 == static_cast<double>(x2) / y2);
    }
}
