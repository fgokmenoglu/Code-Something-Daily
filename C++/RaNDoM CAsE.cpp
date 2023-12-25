/*
 * Write a function that will randomly upper and lower characters in a string.
 * 
 * A few examples:
 * randomCase("Lorem ipsum dolor sit amet, consectetur adipiscing elit") == "lOReM ipSum DOloR SiT AmeT, cOnsEcTEtuR aDiPiSciNG eLIt"
 * randomCase("Donec eleifend cursus lobortis") == "DONeC ElEifEnD CuRsuS LoBoRTIs"
 *
 * Notes:
 * This function will work within the basic ASCII character set to make this kata easier - so no need to make the function multibyte safe.
 * The letters MUST be selected randomly - filters are set to make sure there is no cheating!
 */
#include <string>
#include <random>
#include <functional>
#include <cctype>

std::string randomCase(std::string x) {
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, 1); // Define the range

    for (size_t i = 0; i < x.length(); ++i) {
        bool toggle = distr(eng) == 1; // Randomly decide to toggle case

        if (std::isalpha(x[i])) { // Check if the character is alphabetic
            if (toggle) {
                x[i] = std::islower(x[i]) ? std::toupper(x[i]) : std::tolower(x[i]);
            }
        }
    }

    return x;
}

// ALTERNATIVE
#include <string>
#include <random>

std::string randomCase(std::string x) {
  for (auto& c : x)
    c = rand() % 2 ? std::tolower(c) : std::toupper(c);
    
  return x;
}
