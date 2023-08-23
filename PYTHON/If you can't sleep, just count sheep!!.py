"""
If you can't sleep, just count sheep!!

Task:
Given a non-negative integer, 3 for example, return a string with a murmur: "1 sheep...2 sheep...3 sheep...". Input will always be valid, i.e. no negative integers.
"""
def count_sheep(n):
    result = ""
    
    for i in range(n):
        result += (str(i + 1) + ' sheep...')
    
    return result    

# ALTERNATIVE
# As a reminder, in Python strings are immutable, thus adding to a string is an expensive operation.
# return ''.join(f'{i} sheep...' for i in range(1, n + 1))
