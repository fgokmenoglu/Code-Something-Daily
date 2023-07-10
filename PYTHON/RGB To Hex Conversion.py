"""
The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
"""
def rgb(r, g, b):
    if r < 0: 
        r = 0 
    elif r > 255: 
        r = 255
        
    if g < 0: 
        g = 0 
    elif g > 255: 
        g = 255
        
    if b < 0: 
        b = 0 
    elif b > 255: 
        b = 255

    # Alternative
    # round = lambda x: min(255, max(x, 0))
    
    hex_r = hex(r).replace('0x', '')
    hex_g = hex(g).replace('0x', '')
    hex_b = hex(b).replace('0x', '')
    
    return f"{hex_r:>02}{hex_g:>02}{hex_b:>02}".upper()

    # Alternative
    # return f"{round(r):02X}{round(g):02X}{round(b):02X}"
    
