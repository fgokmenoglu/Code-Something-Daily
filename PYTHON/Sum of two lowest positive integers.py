"""
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.
"""
def sum_two_smallest_numbers(numbers):
    return sum(sorted(numbers)[0:2])

# ALTERNATIVE USING FOR LOOP
"""
def sum_two_smallest_numbers(numbers):
    min1, min2 = numbers[0:2]
    
    for i in range(2, len(numbers)):
        if numbers[i] < min2 and numbers[i] < min1:
            min1 = numbers[i]
        elif min1 < numbers[i] < min2:
            min2 = numbers[i]
            
    return min1 + min2
"""
