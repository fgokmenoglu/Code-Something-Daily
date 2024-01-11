/*
 * INTRODUCTION
 * The built-in number types in C++ can be divided into integers and floating points. 
 * Integers are whole numbers like 0, 691, or -2. 
 * Floating point numbers are numbers with a decimal point like 6.02214076, 0.1, or -1.616.
 * NOTES
 * The result from the operation between two integers is also an integer. 
 * Example: 5 / 2 will return 2. 
 * When one of the involved types is a floating-point type, the result will also be of a floating-point. 
 * Example: 5.0 / 2 and 5 / 2.0 will return 2.5.
 * The assignment operation always takes place from right to left, and never the other way around.
 */

/*
 * TASK 1: Implement a function called daily_rate to calculate the daily rate given an hourly rate as a parameter. The contract defines that a day has 8 billable hours.
 * TASK 2: Implement a function apply_discount to calculates the price after a discount. It should accept two parameters: the original price and the discount rate in percent.
 * TASK 3: Implement a monthly_rate function to calculate the discounted monthly rate. It should have two parameters, an hourly rate and the discount in percent.
 * TASK 4: Implement a function days_in_budget that takes a budget, an hourly rate, and a discount, and calculates how many complete days of work that covers.
 */

// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    // TODO: Implement a function to calculate the daily rate given an hourly
    // rate
    return hourly_rate * 8;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    // TODO: Implement a function to calculate the price after a discount.
    return before_discount * (1 - discount / 100);
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    // TODO: Implement a function to calculate the monthly rate, and apply a
    // discount.
    double dailyRate = daily_rate(hourly_rate);
    double monthlyRate = dailyRate * 22;
    int discountedMonthlyRate = ceil(apply_discount(monthlyRate, discount));
    
    return discountedMonthlyRate;
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // TODO: Implement a function that takes a budget, an hourly rate, and a
    // discount, and calculates how many complete days of work that covers.
    double dailyRate = daily_rate(hourly_rate);
    double discountedDailyRate = apply_discount(dailyRate, discount);
    int workDaysInBudget = floor(budget / discountedDailyRate);
    
    return workDaysInBudget;
}
