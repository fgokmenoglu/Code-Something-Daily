#include "grains.h"

namespace grains {
    unsigned long long square(int n) {
        unsigned long long out = 0;

        out = pow(2, n - 1);
        
        return out;
    }

    unsigned long long total() {
        unsigned long long out = 0;

        for (unsigned long long i = 1; i <= 64; ++i)
            out += pow(2, i - 1);
        
        return out - 1;
    }
}  // namespace grains
