#include <string>
#include <sstream>
#include <iomanip>

/*
 * Task:
 * The rgb function is incomplete. Complete it so that passing in RGB decimal values
 * will result in a hexadecimal representation being returned. Valid decimal values
 * for RGB are 0 - 255. Any values that fall out of that range must be rounded to
 * the closest valid value.
 *
 * Note: 
 * Your answer should always be 6 characters long, the shorthand with 3 will not work here.
 */

std::string rgb_to_hex(int r, int g, int b) {
    // Helper function to clamp values between 0 and 255
    auto clamp = [](int value) {
        return std::max(0, std::min(255, value));
    };

    // Clamp the input values
    r = clamp(r);
    g = clamp(g);
    b = clamp(b);

    // Convert to hexadecimal
    std::stringstream ss;
    ss << std::uppercase << std::hex << std::setfill('0')
       << std::setw(2) << r
       << std::setw(2) << g
       << std::setw(2) << b;

    return ss.str();
}
