/*
 * Complete the function which converts hex number (given as a string) to a decimal number.
 */
#include <string>

int hexToDec(std::string hexString) {
  return std::stoi(hexString, nullptr, 16);
}
