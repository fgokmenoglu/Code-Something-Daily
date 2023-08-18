"""
Define a function that takes in two non-negative integers a and b and returns the last decimal digit of a^b. 
Note that a and b may be very large!

You may assume that the input will always be valid.

Examples
last_digit(4, 1)                # returns 4
last_digit(4, 2)                # returns 6
last_digit(9, 7)                # returns 9
last_digit(10, 10 ** 10)        # returns 0
last_digit(2 ** 200, 2 ** 300)  # returns 6
"""
last_digit_pattern = {
    0 : [0],
    1 : [1],
    2 : [2, 4, 6, 8],
    3 : [3, 9, 7, 1],
    4 : [4, 6],
    5 : [5],
    6 : [6],
    7 : [7, 9, 3, 1],
    8 : [8, 4, 2, 6],
    9 : [9, 1]
}

def last_digit(n1, n2):
    if n2 == 0:
        return 1
    
    remainder1 = n1 % 10
    
    if len(last_digit_pattern[remainder1]) == 1:
        return last_digit_pattern[remainder1][0]
    
    remainder2 = n2 % len(last_digit_pattern[remainder1])
    return last_digit_pattern[remainder1][remainder2 - 1]

# ALTERNATIVE
"""
E = [
  [0, 0, 0, 0], [1, 1, 1, 1],
  [6, 2, 4, 8], [1, 3, 9, 7],
  [6, 4, 6, 4], [5, 5, 5, 5],
  [6, 6, 6, 6], [1, 7, 9, 3],
  [6, 8, 4, 2], [1, 9, 1, 9]
]

def last_digit(n1, n2):
    if n2 == 0: return 1
    return E[n1 % 10][n2 % 4]
"""
