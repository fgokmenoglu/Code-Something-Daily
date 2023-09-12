"""
This time no story, no theory. The examples below show you how to write function accum:

Examples:
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"

The parameter of accum is a string which includes only letters from a..z and A..Z.
"""
def accum(s):
    result = []
    i = 1
    
    for c in s:
        temp = c * i
        temp = temp[0].upper() + temp[1:].lower()
        result.append(temp)    
        i += 1
        
    return '-'.join(result)

# ALTERNATIVE
"""
def accum(s):
    return '-'.join((a * i).title() for i, a in enumerate(s, 1))
"""
