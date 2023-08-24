"""
You are given an array(list) strarr of strings and an integer k. Your task is to return the first longest string consisting of k consecutive strings taken in the array.

Examples:
strarr = ["tree", "foling", "trashy", "blue", "abcdef", "uvwxyz"], k = 2

Concatenate the consecutive strings of strarr by 2, we get:

treefoling   (length 10)  concatenation of strarr[0] and strarr[1]
folingtrashy ("      12)  concatenation of strarr[1] and strarr[2]
trashyblue   ("      10)  concatenation of strarr[2] and strarr[3]
blueabcdef   ("      10)  concatenation of strarr[3] and strarr[4]
abcdefuvwxyz ("      12)  concatenation of strarr[4] and strarr[5]

Two strings are the longest: "folingtrashy" and "abcdefuvwxyz".
The first that came is "folingtrashy" so 
longest_consec(strarr, 2) should return "folingtrashy".

In the same way:
longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"], 2) --> "abigailtheta"
n being the length of the string array, if n = 0 or k > n or k <= 0 return "" (return Nothing in Elm, "nothing" in Erlang).

Note
consecutive strings : follow one after another without an interruption
"""
def longest_consec(strarr, k):
    n = len(strarr)
    
    if (n == 0 or k > n or k <= 0):
        return ''
    
    substring = '';
    substring_length = 0;
    
    for i in range(n):
        temp_substring = ''.join(strarr[i:i + k])
        temp_substring_length = len(temp_substring);
        
        if temp_substring_length > substring_length:
            substring = temp_substring;
            substring_length = temp_substring_length;

    return substring

# ALTERNATIVE NOT USING JOIN IN EACH ITERATION SINCE IT IS NOT EFFICIENT"
"""
def longest_consec(strarr, k):
    n = len(strarr)
    if n == 0 or k > n or k <= 0:
        return ''
        
    length = sum(len(strarr[i]) for i in range(k))
    max_length = length
    max_index = 0
    for index in range(0, n - k):
        length += len(strarr[index + k]) - len(strarr[index])
        if length > max_length:
            max_length, max_index = length, index + 1
    
    return ''.join(strarr[max_index:max_index + k])
"""
