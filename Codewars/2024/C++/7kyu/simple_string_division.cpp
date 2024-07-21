/*
 * In this Kata, you will be given a number in form of a string and an integer k 
 * and your task is to insert k commas into the string and determine which of the partitions is the largest.
 *
 * For example:
 * solve('1234',1) = 234 because ('1','234') or ('12','34') or ('123','4').
 * solve('1234',2) = 34 because ('1','2','34') or ('1','23','4') or ('12','3','4'). 
 * solve('1234',3) = 4
 * solve('2020',1) = 202
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

long long solve(std::string st, int k) {
    std::cout << "st: " << st << "\n";
    std::cout << "k: " << k << "\n";
    int n = st.length();
    if (k >= n) return 0;  // Edge case: more commas than digits
    
    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(n, 0));
    
    // Initialize dp for 0 commas (base case)
    for (int i = 0; i < n; i++) {
        dp[0][i] = std::stoll(st.substr(0, i + 1));
    }
    
    // For each number of commas from 1 to k
    for (int commas = 1; commas <= k; commas++) {
        // For each possible ending position of the current partition
        for (int i = commas; i < n; i++) {
            // Try all possible starting positions for the current partition
            for (int j = commas - 1; j < i; j++) {
                long long current_partition = std::stoll(st.substr(j + 1, i - j));
                dp[commas][i] = std::max(dp[commas][i], std::max(dp[commas-1][j], current_partition));
            }
        }
    }
    
    return dp[k][n - 1];
}

// ALTERNATIVE
long long solve(const std::string &s, size_t k) {
    long long max = 0;
    for (size_t i = 0, h = s.size() - k; i <= k; ++i)
        max = std::max(max, std::stoll(s.substr(i, h)));
    return max;
}
