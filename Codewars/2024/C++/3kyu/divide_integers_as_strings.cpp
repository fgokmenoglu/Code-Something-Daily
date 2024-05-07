/*
 * Given positive integers a and b as strings, evaluate a / b 
 * and return the quotient and the remainder as strings in the form 
 * [quotient, remainder] (vector<string> {quotient, remainder} in C++).
 *
 * a and b can be very large (at the order of 10^150 to 10^200)
 * Your result should not have leading 0s
 */
#include <vector>
#include <string>

using namespace std;

// Function to subtract two string numbers where the first is guaranteed to be larger than or equal to the second
string subtract(const string& a, const string& b) {
    int la = a.size(), lb = b.size();
    int carry = 0, i = la - 1, j = lb - 1;
    string result(la, '0');
    
    while (i >= 0) {
        int digitA = a[i] - '0';
        int digitB = j >= 0 ? b[j] - '0' : 0;
        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result[i] = '0' + diff;
        i--;
        j--;
    }
    
    size_t start = result.find_first_not_of('0');
    return start != string::npos ? result.substr(start) : "0";
}

// Function to compare two string numbers
int compare(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() > b.size() ? 1 : -1;
    return a.compare(b);
}

// Function for long string division
vector<string> divide_strings(const string& a, const string& b) {
    if (b == "0") {
        throw invalid_argument("Division by zero");
    }
    
    string quotient;
    string remainder;
    size_t n = a.size();
    
    for (size_t i = 0; i < n; ++i) {
        remainder += a[i];
        // Remove leading zeros
        remainder.erase(0, remainder.find_first_not_of('0'));
        if (remainder.empty()) remainder = "0";
        
        int count = 0;
        while (compare(remainder, b) >= 0) {
            remainder = subtract(remainder, b);
            count++;
        }
        quotient += to_string(count);
    }
    
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty()) quotient = "0";
    if (remainder.empty()) remainder = "0";
    
    return {quotient, remainder};
}
