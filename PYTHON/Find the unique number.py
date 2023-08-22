"""
There is an array with some numbers. All numbers are equal except for one. Try to find it!

find_uniq([ 1, 1, 1, 2, 1, 1 ]) == 2
find_uniq([ 0, 0, 0.55, 0, 0 ]) == 0.55
It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.
"""
from collections import Counter

def find_uniq(arr):
    # temp = {i : arr.count(i) for i in arr}
    # print(temp)
    # return min(temp, key=temp.get)
    temp = Counter(arr)
    return min(temp, key=temp.get)
  
# ALTERNATIVE USING SET
"""
def find_uniq(arr):
    a, b = set(arr)
    return a if arr.count(a) == 1 else b
"""
