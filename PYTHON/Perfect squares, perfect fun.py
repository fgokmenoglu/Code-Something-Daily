"""
Given an integer, if the length of it's digits is a perfect square, return a square block of sqroot(length) * sqroot(length). If not, simply return "Not a perfect square!".

Examples:

1212 returns:

12
12 

Note: 4 digits so 2 squared (2x2 perfect square). 2 digits on each line.

123123123 returns:

123
123
123

Note: 9 digits so 3 squared (3x3 perfect square). 3 digits on each line.
"""
def square_it(digits):
    temp = list(str(digits))
    # print(temp)
    num_of_digits = len(temp)
    square_root = num_of_digits ** 0.5
    square_root = int(square_root + 0.5)
    
    if square_root * square_root != num_of_digits:
        return "Not a perfect square!"
    
    result = ""
    
    for i in range(0, num_of_digits, int(square_root)):
        result += (''.join(temp[i:i + int(square_root)]) + '\n')                         
    
    return result[:len(result) - 1]

# ALTERNATIVE
"""
def square_it(digits):
    s = str(digits)
    n = len(s)**0.5
    if n != int(n):
        return "Not a perfect square!"
    n = int(n)
    return "\n".join(s[i*n:i*n+n] for i in range(int(n)))
"""
