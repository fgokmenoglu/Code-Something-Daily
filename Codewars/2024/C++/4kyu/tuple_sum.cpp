/*
 * Your task is to implement a function that adds all tuple elements that are numbers.
 * For this kata chars are not considered numbers.
 */
#include <tuple>
#include <type_traits>
#include <string>
#include <vector>

// Helper type trait to determine if a type is numeric but not a character or a pointer
template<typename T>
constexpr bool is_numeric_not_char_not_pointer =
    std::is_arithmetic_v<std::decay_t<T>> &&
    !std::is_same_v<std::decay_t<T>, char> && // assuming you want to exclude char
    !std::is_pointer_v<std::decay_t<T>>;      // exclude pointers

// Function to sum up numeric values in a tuple
template <typename... Ts>
auto tuple_sum(const std::tuple<Ts...>& tpl) -> decltype(auto) {
    return std::apply([](auto&&... args) {
        double sum = 0.0;
        // Using a fold expression with if constexpr to safely sum only valid types
        ([&sum](const auto& arg) {
            if constexpr (is_numeric_not_char_not_pointer<decltype(arg)>) {
                sum += arg;
            }
        }(args), ...);
        return sum;
    }, tpl);
}
