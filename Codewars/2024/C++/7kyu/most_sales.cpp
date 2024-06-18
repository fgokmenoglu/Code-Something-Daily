/*
 * You work in the best consumer electronics corporation, 
 * and your boss wants to find out which three products generate the most revenue. 
 * Given 3 lists of the same length like these:
 *
 * products: ["Computer", "Cell Phones", "Vacuum Cleaner"]
 * amounts: [3, 24, 8]
 * prices: [199, 299, 399]
 * return the three product names with the highest revenue (amount * price).
 * 
 * Note: if multiple products have the same revenue, order them according to their original positions in the input list.
 */
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

// Function to find the top 3 products with the highest revenue
std::vector<std::string> top3(
        const std::vector<std::string>& products,
        const std::vector<int>& amounts,
        const std::vector<int>& prices) {
    // Create a vector of tuples to hold product name and its revenue
    std::vector<std::tuple<std::string, int, int>> product_revenues;
    for (size_t i = 0; i < products.size(); ++i) {
        int revenue = amounts[i] * prices[i];
        product_revenues.emplace_back(products[i], revenue, i);
    }

    // Sort the vector by revenue in descending order
    std::sort(product_revenues.begin(), product_revenues.end(),
              [](const std::tuple<std::string, int, int>& a, 
                 const std::tuple<std::string, int, int>& b) {
        if (std::get<1>(a) == std::get<1>(b)) {
            return std::get<2>(a) < std::get<2>(b); // maintain original order if revenues are equal
        }
        return std::get<1>(a) > std::get<1>(b); // sort by revenue
    });

    // Extract the top 3 products
    std::vector<std::string> top_products;
    for (size_t i = 0; i < 3 && i < product_revenues.size(); ++i) {
        top_products.push_back(std::get<0>(product_revenues[i]));
    }

    return top_products;
}
