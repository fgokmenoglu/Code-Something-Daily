/*
 * Calling make_me_slow() should take at least 7 seconds.
 */
#include <thread>
#include <chrono>

void make_me_slow() {
    // Sleep for 7 seconds
    std::this_thread::sleep_for(std::chrono::seconds(7));
    
    // Optional: Keep the existing loop for additional processing
    for (int x = 0; x < 1000000; x++);
}
