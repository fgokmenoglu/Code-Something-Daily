"""
Yup!! The problem name reflects your task; just add a set of numbers. But you may feel yourselves condescended, to write a program just to add a set of numbers. Such a problem will simply question your erudition. So, let's add some flavor of ingenuity to it. Addition operation requires cost now, and the cost is the summation of those two to be added. So, to add 1 and 10, you need a cost of 11. If you want to add 1, 2 and 3, there are several ways:

1 + 2 = 3, cost = 3,
3 + 3 = 6, cost = 6,
Total = 9.

1 + 3 = 4, cost = 4,
2 + 4 = 6, cost = 6,
Total = 10.

2 + 3 = 5, cost = 5,
1 + 5 = 6, cost = 6,
Total = 11.

I hope you have understood already your mission: to add a set of integers so that the cost is minimal.

Your Task
Given a vector of integers, return the minimum total cost of addition.
"""
import heapq

def add_all(lst):
    result = 0
    
    heapq.heapify(lst)
    
    while len(lst) > 1:
        first = heapq.heappop(lst)
        second = heapq.heappop(lst)
        
        result += first + second
        heapq.heappush(lst, first + second)
    
    return result
    
"""
Heap queue is a special tree structure in which each parent node is less than or equal to its child node. 
In python it is implemented using the heapq module. 
It is very useful is implementing priority queues where the queue item with higher weight is given more priority in processing.
"""

# ALTERNATIVE
def add_all(lst):
    result = []
  
    while len(lst) > 1:
        lst.sort()
      
        firstTwoFromList = lst.pop(0) + lst.pop(0)
        lst.append(firstTwoFromList)
        result.append(firstTwoFromList)
      
    return sum(result)
