/*
 * Given a string, return the minimal number of 
 * parenthesis reversals needed to make balanced parenthesis.
 *
 * For example:
 * solve(")(") = 2 Because we need to reverse ")" to "(" and "(" to ")". These are 2 reversals. 
 * solve("(((())") = 1 We need to reverse just one "(" parenthesis to make it balanced.
 * solve("(((") = -1 Not possible to form balanced parenthesis. Return -1.
 *
 * Parenthesis will be either "(" or ")".
 */
#include <string>
#include <stack>

int solve(std::string s) {
    int len = s.length();
    
    // If length is odd, it's impossible to balance
    if (len % 2 != 0) {
        return -1;
    }
    
    std::stack<char> st;
    int reversals = 0;
    
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else { // c == ')'
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                reversals++;
                st.push('(');
            }
        }
    }
    
    // Add remaining opening parentheses
    reversals += st.size() / 2;
    
    return reversals;
}
