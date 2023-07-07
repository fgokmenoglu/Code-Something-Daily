"""
Complete the solution so that the function will break up camel casing, using a space between words.

Example
"camelCasing"  =>  "camel Casing"
"identifier"   =>  "identifier"
""             =>  ""
"""
import re

pattern = r'[a-zA-Z][^A-Z]*'

def solution(s):
    return ' '.join(re.findall(pattern, s))
