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
      
