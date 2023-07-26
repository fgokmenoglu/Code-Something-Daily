"""
Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. For example:

  12 ==> 21
 513 ==> 531
2017 ==> 2071
If the digits can't be rearranged to form a bigger number, return -1 (or nil in Swift, None in Rust):

  9 ==> -1
111 ==> -1
531 ==> -1
"""
# HAVING A TIMEOUT PROBLEM WITH THIS SOLUTION (TIMEOUT SET TO 12000 MS)
import itertools

def next_bigger(n):
    possible_numbers = set()
    
    digits = [int(i) for i in list(str(n))]
    # print(digits)
    
    for i in range(1, len(digits) + 1):
        combinations = list(itertools.permutations(digits, i))
        # print(combinations)
        
        for j in range(len(combinations)):
            temp = 0
            
            for k in range(len(combinations[j])):     
                temp += combinations[j][k] * (10 ** k)
                
            possible_numbers.add(temp)
    
    possible_numbers = list(possible_numbers)
    possible_numbers.sort()
    # print(possible_numbers)
    
    for number in possible_numbers:
        # print(number)
        index = possible_numbers.index(n)
        # print(index)
        
        if index == (len(possible_numbers) - 1):
            return (-1,)[0]
        else:
            return possible_numbers[index + 1]
