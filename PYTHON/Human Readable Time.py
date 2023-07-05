"""
Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)

HH = hours, padded to 2 digits, range: 00 - 99
MM = minutes, padded to 2 digits, range: 00 - 59
SS = seconds, padded to 2 digits, range: 00 - 59
The maximum time never exceeds 359999 (99:59:59)

You can find some examples in the test fixtures.
"""
def make_readable(seconds):
    # Do something
    HH = seconds // 3600
    # print(HH)
    MM = seconds % 3600 // 60
    # print(MM)
    SS = seconds % 60
    # print(SS)
    
    return f"{HH:02d}:{MM:02d}:{SS:02d}"
