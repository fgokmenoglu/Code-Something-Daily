"""
Welcome.

In this kata you are required to, given a string, replace every letter with its position in the alphabet.

If anything in the text isn't a letter, ignore it and don't return it.

"a" = 1, "b" = 2, etc.

Example
alphabet_position("The sunset sets at twelve o' clock.")
Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" ( as a string )
"""
def alphabet_position(text):
    # print(f"before {text}")
    result = []
    
    for c in text:
        c = c.lower()
        c = ord(c) - 96
        
        if (1 <= c <= 26):
            result.append(str(c))
    
    # print(f"after {' '.join(result)}")
    return ' '.join(result)

# ALTERNATIVE
# return ' '.join(str(ord(c) - 96) for c in text.lower() if c.isalpha())
# The isalpha() method returns True if all the characters are alphabet letters (a-z).
