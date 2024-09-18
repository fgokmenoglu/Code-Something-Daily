#include <vector>
#include <algorithm>

/**
 * @brief Calculates the total time required for all customers to check out.
 * 
 * This function simulates a queue for self-checkout tills at a supermarket.
 * It determines the total time needed for all customers to complete their checkout
 * given a specific number of available tills.
 * 
 * @param customers A vector of positive integers representing the queue.
 *                  Each integer represents a customer, and its value is the
 *                  amount of time they require to check out.
 * @param n The number of checkout tills available.
 * @return long The total time required for all customers to check out.
 */
long queueTime(std::vector<int> customers, int n) {
    if (customers.empty()) return 0;
    if (n <= 0) return 0;  // Handle edge case of no tills

    std::vector<long> tills(n, 0);  // Initialize tills with 0 time

    for (int customer : customers) {
        // Find the till with the minimum time and add the customer to it
        auto minTill = std::min_element(tills.begin(), tills.end());
        *minTill += customer;
    }

    // Return the maximum time among all tills
    return *std::max_element(tills.begin(), tills.end());
}
