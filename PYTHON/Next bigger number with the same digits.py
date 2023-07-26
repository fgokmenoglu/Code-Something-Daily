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
    digits = list(str(n))
    # print(digits)
    
    permutations = list(itertools.permutations(digits, len(digits)))
    # print(permutations)
    
    for permutation in permutations:
        possible_numbers.add(int(''.join(permutation)))    
        
    possible_numbers = list(possible_numbers)
    possible_numbers.sort()
    # print(possible_numbers)    

    for number in possible_numbers:
        index = possible_numbers.index(n)
        
        if index == (len(possible_numbers) - 1):
            return (-1,)[0]
        else:
            return possible_numbers[index + 1]

# ALTERNATIVE
"""
def next_bigger(n):
    # algorithm: go backwards through the digits
    # when we find one that's lower than any of those behind it,
    # replace it with the lowest digit behind that's still higher than it
    # sort the remaining ones ascending and add them to the end
    digits = list(str(n))
    for pos, d in reversed(tuple(enumerate(digits))):
        right_side = digits[pos:]
        if d < max(right_side):
            # find lowest digit to the right that's still higher than d
            first_d, first_pos = min((v, p) for p, v in enumerate(right_side) if v > d)

            del right_side[first_pos]
            digits[pos:] = [first_d] + sorted(right_side)

            return int(''.join(digits))

    return -1
"""
