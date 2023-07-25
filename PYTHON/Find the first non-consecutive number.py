"""
Your task is to find the first element of an array that is not consecutive.

By not consecutive we mean not exactly 1 larger than the previous element of the array.

E.g. If we have an array [1,2,3,4,6,7,8] then 1 then 2 then 3 then 4 are all consecutive but 6 is not, so that's the first non-consecutive number.

If the whole array is consecutive then return None.

The array will always have at least 2 elements1 and all elements will be numbers. The numbers will also all be unique and in ascending order. The numbers could be positive or negative and the first non-consecutive could be either too!
"""
def first_non_consecutive(arr):
    for i in range(len(arr) - 1):
        if arr[i + 1] - arr[i] != 1:
            return arr[i + 1]
        
    return None

# ALTERNATIVE USING ENUMERATE
# def first_non_consecutive(arr):
#     for i, v in enumerate(arr, arr[0]):
#         if v != i:
#             return v

"""
Python automatically adds implicit return statements to the end of any function that you’ll write. 
So therefore, if a function does not specify a return value, it will return None by default.
"""
