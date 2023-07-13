"""
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros([1, 0, 1, 2, 0, 1, 3]) # returns [1, 1, 2, 1, 3, 0, 0]
"""
def move_zeros(lst):
    num_of_zeros = lst.count(0)
    # print(num_of_zeros)
    
    lst = list(filter(None, lst))
    # print(lst)
    
    for i in range(num_of_zeros):
        lst.append(0)
    
    # print(lst)
    return lst
