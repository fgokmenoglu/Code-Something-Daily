"""
Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

Examples
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
"""
def digital_root(n):
    # ...
    result = 0
    
    while n > 10:
        result += (n % 10)
        n = n // 10
    
    if result < 10:
        return result
    else:
        return digital_root(result)

# Alternative
# def digital_root(n):
#   return n if n < 10 else digital_root(sum(map(int,str(n))))
