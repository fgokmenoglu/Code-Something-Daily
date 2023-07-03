"""
Your goal in this kata is to implement a difference function, which subtracts one list from another and returns the result.

It should remove all values from list a, which are present in list b keeping their order.

array_diff([1,2],[1]) == [2]
If a value is present in b, all of its occurrences must be removed from the other:

array_diff([1,2,2,2,3],[2]) == [1,3]
"""
def array_diff(a, b):
    #your code here
    for element_b in b:
        a = [element_a for element_a in a if element_a != element_b]
        
    return a

    # Alternative
    # b_set = set(b)

    # return [item for item in a if item not in b_set]

"""
Source: https://stackoverflow.com/questions/8929284/what-makes-sets-faster-than-lists  

Sets are implemented using hash tables. Whenever you add an object to a set, the position within the memory of the set object is determined using the hash of the object to be added. 
When testing for membership, all that needs to be done is basically to look if the object is at the position determined by its hash, so the speed of this operation does not depend on the size of the set. 
For lists, in contrast, the whole list needs to be searched, which will become slower as the list grows.
This is also the reason that sets do not preserve the order of the objects you add.
Note that sets aren't faster than lists in general -- membership test is faster for sets, and so is removing an element. As long as you don't need these operations, lists are often faster.
"""
