#include "raindrops.h"

namespace raindrops {
    std::string convert(int num) {
        std::string out = "";
        
        if (num % 3 == 0) out += "Pling";
        if (num % 5 == 0) out += "Plang";
        if (num % 7 == 0) out += "Plong";
        if (out == "") out = std::to_string(num);
        
        return out;   
    }
}  // namespace raindrops
