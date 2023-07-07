"""
Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"

"The_Stealth_Warrior" gets converted to "TheStealthWarrior"

"The_Stealth-Warrior" gets converted to "TheStealthWarrior"
"""
import re

pattern = r'[-_]'

def to_camel_case(text):
    words = re.split(pattern, text)
    # print(words)
    result = ''.join([word.capitalize() for word in words])
    # print(result)
    
    if words:
        if words[0].islower():
            result = result[:1].lower() + result[1:]
    
    return result

# Alternative
# words = re.split(pattern, text)
# if words
#   return words[0] + ''.join([word.capitalize() for word in words[1:])
# else
#   return ''

# Alternative
# return text[:1] + text.title()[1:].replace('_', '').replace('-', '')
# Slicing an empty list will return the empty list itself
