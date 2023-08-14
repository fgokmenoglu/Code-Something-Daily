"""
Letter with Tail
We got a string of letters made up by Os and/or Xs (or an empty string).

In this Kata, a Letter with Tail can be either one of the following:

O followed by 1 or more X, such as OX, OXX, OXXX, etc.

X followed by 1 or more O, such as XO, XOO, XOOO, etc.

Total Possible Amount
In most of the cases, we can find more than 1 way to get Letter with Tails.

And we are looking for the cases: Every single character from the input cannot occur in two or more different Letter with Tails.

For example, input string is 'OXXO'

(We use parentheses to show the Letter with Tails we got in the example)

(OX)XO, (OXX)O, OX(XO), (OX)(XO)
There are 4 of them. We call the number total possible amount.

Task
Input: Getting a string of letters made up by Os and/or Xs (or an empty string).

Return: Return the total possible amount for the input string.

0 <= string length <= 90

With the string length limit, the answer will not be bigger than 2^64.

Example:
Input String is 'XOOOXXO'

1 Letter with Tail:

(XO)OOXXO, (XOO)OXXO, (XOOO)XXO, XOO(OX)XO, XOO(OXX)O, XOOOX(XO)


2 Letter with Tails:

(XO)O(OX)XO, (XO)O(OXX)O, (XO)OOX(XO), (XOO)(OX)XO, (XOO)(OXX)O, (XOO)OX(XO), (XOOO)X(XO), XOO(OX)(XO)


3 Letter with Tails:

(XO)O(OX)(XO), (XOO)(OX)(XO)
So the answer is 16.

Sample Tests:
Input => Output

'' => 0
'OOO' => 0
'XX' => 0
'XXXXO' => 1
'OXX' => 2
'OXOX' => 4
'OXXO' => 4
'XOXOX' => 7
'XOOOXXO' => 16
'XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO' => 63245985
"""
from functools import lru_cache

def total_possible_amount(s):
    @lru_cache(None)
    def f(pos, head):
        tail = {'X':'O','O':'X'}[head]
        return pos == len(s) or f(pos + 1, head) + (s[pos] != head and f(pos, tail))
    
    return f(1, s[0]) - 1 if s else 0

# lru_cache() is one such function in functools module which helps in reducing the execution time of the function by using memoization technique.
