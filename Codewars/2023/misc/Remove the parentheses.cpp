/*
 * In this kata you are given a string for example:
 * 
 * "example(unwanted thing)example"
 * Your task is to remove everything inside the parentheses as well as the parentheses themselves.
 * 
 * The example above would return:
 * "exampleexample"
 * 
 * Notes
 * Other than parentheses only letters and spaces can occur in the string. Don't worry about other brackets like "[]" and "{}" as these will never appear.
 * There can be multiple parentheses.
 * The parentheses can be nested.
 */
#include <string>
#include <stack>

std::string remove_parentheses(const std::string &str) {
    std::string result;
    std::stack<int> parentheses; // Stack to keep track of parentheses

    for (char ch : str) {
        if (ch == '(') {
            // When an opening parenthesis is found, push its position onto the stack
            parentheses.push(result.size());
        } else if (ch == ')' && !parentheses.empty()) {
            // When a closing parenthesis is found, remove everything from the last opening parenthesis
            result.erase(parentheses.top());
            parentheses.pop();
        } else if (parentheses.empty()) {
            // Add characters to the result if they are not within parentheses
            result += ch;
        }
    }

    return result;
}

// ALTERNATIVE
#include <string>

std::string remove_parentheses(const std::string &str) {
  std::string result;
  int paranthesis = 0;
  
  for (const char& ch: str) 
    if (ch == '(') paranthesis++ ;
      else if (ch == ')') paranthesis--; 
        else if (!paranthesis) result = result + ch;
  return result;
}
