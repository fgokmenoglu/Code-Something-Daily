"""
You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)
"""
def find_outlier(integers):
    temp = [i for i in integers if i % 2 == 1]
    temp2 = [i for i in integers if i not in temp]
    # print(temp)
    # print(temp2)
    
    if len(temp2) == 1:
        return temp2[0]
    else:
        return temp[0]

# ALTERNATIVE
#    parity = [n % 2 for n in integers]
#    return integers[parity.index(1)] if sum(parity) == 1 else integers[parity.index(0)]
#
# The index() method returns the position at the first occurrence of the specified value.
