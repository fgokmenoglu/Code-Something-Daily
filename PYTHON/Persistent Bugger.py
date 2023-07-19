"""
Write a function, persistence, that takes in a positive parameter num and returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

For example (Input --> Output):

39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit)
999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 = 2)
4 --> 0 (because 4 is already a one-digit number)
"""
from functools import reduce

def persistence(n):
    temp = list(str(n))
    print(temp)
    count = 0
    
    if len(temp) == 1:
        return 0
    else:
        while len(temp) > 1:
            result = reduce((lambda x, y: x * y), [int(i) for i in temp])
            count += 1
            temp = list(str(result))
    
    return count

# ALTERNATIVE
# def persistence(n):
#     count = 0
#    
#     while n >= 10:
#         n = reduce((lambda x, y: x * y), [int(i) for i in str(n)])
#         count += 1
#    
#     return count
