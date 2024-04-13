/*
 * To introduce the problem think to my neighbor who drives a tanker truck. 
 * The level indicator is down and he is worried because he does not know if he will be able to make deliveries. 
 * We put the truck on a horizontal ground and measured the height of the liquid in the tank.
 * 
 * Fortunately the tank is a perfect cylinder and the vertical walls on each end are flat. 
 * The height of the remaining liquid is h, the diameter of the cylinder base is d, the total volume is vt (h, d, vt are positive or null integers). 
 * You can assume that h <= d.
 *
 * Could you calculate the remaining volume of the liquid? Your function tankvol(h, d, vt) returns an integer which is the truncated result (e.g floor) of your float calculation.
 *
 * Examples:
 * tankvol(40,120,3500) should return 1021 (calculation gives about: 1021.26992027)
 * tankvol(60,120,3500) should return 1750
 * tankvol(80,120,3500) should return 2478 (calculation gives about: 2478.73007973)
 */
#include <cmath> // Include cmath for math functions

class VolTank {
public:
    static int tankVol(int h, int d, int vt) {
        double R = d / 2.0;
        double L = vt / (M_PI * R * R);
        double area;

        if (h == 0) {
            return 0; // If no liquid, volume is 0
        } else if (h == d) {
            return vt; // If completely full, volume is total volume
        } else {
            // Calculate the area of the circular segment
            double term1 = R * R * acos((R - h) / R);
            double term2 = (R - h) * sqrt(2 * R * h - h * h);
            area = term1 - term2;
        }
        // Calculate the volume of liquid and truncate to nearest integer
        double volume = L * area;
        return static_cast<int>(floor(volume));
    }
};

