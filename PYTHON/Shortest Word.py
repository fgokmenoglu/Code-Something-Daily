"""
Simple, given a string of words, return the length of the shortest word(s).

String will never be empty and you do not need to account for different data types.
"""
def find_short(s):
    words = s.split(' ')
    shortest_length = len(words[0])
    
    for word in words:
        current_length = len(word)
        
        if current_length < shortest_length:
            shortest_length = current_length
    
    return shortest_length

# ALTERNATIVES
# return len(min(s.split(' '), key=len))
# return min(len(x) for x in s.split())
