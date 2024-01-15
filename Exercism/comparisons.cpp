/*
 * INTRODUCTION
 * In C++, you can compare values using the comparison operators: <, >, <=, >=, ==, !=
 * The result of these comparisons is always a boolean value.
 * This kind of comparison is available for numbers and strings. 
 * When comparing strings, the dictionary order (also known as lexicographic order) is followed.
 *
 * NOTES
 * Since C++17 if-statements can also include a short initialization statement that can be used to initialize one or more variables for the if statement.
 * Any variables created in the initialization cannot be accessed after the end of the if statement.
 * Example:
 * int num{7};
 *
 * if (int v{2 * num}; v > 10) {
 *   return v;
 * } else {
 *   return num;
 * }
 */

/*
 * TASK 1: Determine if you will need a driver's license
 * TASK 2: Choose between two potential vehicles to buy
 * TASK 3: Calculate an estimation for the price of a used vehicle
 */
#include "vehicle_purchase.h"

namespace vehicle_purchase {

    // needs_license determines whether a license is needed to drive a type of vehicle. Only "car" and "truck" require a license.
    bool needs_license(std::string kind){
        // TODO: Return true if you need a license for that kind of vehicle.
        if (kind == "car" || kind == "truck")
            return true;

        return false;
    }

    // choose_vehicle recommends a vehicle for selection. It always recommends the vehicle that comes first in lexicographical order.
    std::string choose_vehicle(std::string option1, std::string option2) {
        // TODO: Return the final decision in a sentence.
        if (option1 <= option2)
            return option1 + " is clearly the better choice.";
                
        return option2 + " is clearly the better choice.";
    }

    // calculate_resell_price calculates how much a vehicle can resell for at a certain age.
    double calculate_resell_price(double original_price, double age) {
        // TODO: Return the age-corrected resell price.
        double resellPrice = 0.0;

        if (age < 3)
            resellPrice = original_price * 0.8;
        else if (age >= 3 && age < 10)
            resellPrice = original_price * 0.7;
        else
            resellPrice = original_price * 0.5;
        
        return resellPrice;
    }

}  // namespace vehicle_purchase
