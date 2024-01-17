/*
 * Some new cashiers started to work at your restaurant.
 * They are good at taking orders, but they don't know how to capitalize words, or use a space bar!
 * All the orders they create look something like this:
 * 
 * "milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"
 * 
 * The kitchen staff are threatening to quit, because of how difficult it is to read the orders.
 * Their preference is to get the orders as a nice clean string with spaces and capitals like so:
 *
 * "Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke"
 * 
 * The kitchen staff expect the items to be in the same order as they appear in the menu.
 * The menu items are fairly simple, there is no overlap in the names of the items:
 * 
 * 1. Burger
 * 2. Fries
 * 3. Chicken
 * 4. Pizza
 * 5. Sandwich
 * 6. Onionrings
 * 7. Milkshake
 * 8. Coke
 */
#include <string>
#include <vector>
#include <algorithm>

std::string get_order(const std::string &order) {
    std::vector<std::string> menu = {"Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};
    std::string formattedOrder;
    std::string lowerOrder = order;
    std::transform(lowerOrder.begin(), lowerOrder.end(), lowerOrder.begin(), ::tolower);

    for (const auto& item : menu) {
        std::string lowerItem = item;
        std::transform(lowerItem.begin(), lowerItem.end(), lowerItem.begin(), ::tolower);
        std::size_t start = 0;
      
        while ((start = lowerOrder.find(lowerItem, start)) != std::string::npos) {
            formattedOrder += item + " ";
            start += lowerItem.length();
        }
    }

    if (!formattedOrder.empty())
        formattedOrder.pop_back();
    
    return formattedOrder;
}
