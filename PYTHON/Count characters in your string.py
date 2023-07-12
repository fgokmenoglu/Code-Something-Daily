"""
The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.
"""
from collections import Counter

def count(s):
    if s == '':
        return {}
    else:
        chars = list(s)
        # print(list_of_chars)
    
        return dict(zip(Counter(chars).keys(), Counter(chars).values()))

# ALTERNATIVE USING AGAIN! COUNTER
"""
from collections import Counter

def count(string):
    return Counter(string)
"""

"""
Counter is an unordered collection where elements are stored as Dict keys and their count as dict value.
We can create an empty Counter or start with some initial values too.
We can also use any Iterable as argument for creating Counter object. So string literal and List can be used too for creating Counter object.
"""
