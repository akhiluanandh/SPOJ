"""
AUTHOR: Akhilesh Anandh
Solution for "Small Factorials" (www.spoj.com/problems/FCTRL2)
"""

import sys
from array import array 
 
list = []
 
for i in range(0,101):
    list.append(0)
 
list[1]=1
 
def fact(n):
    if(list[n]==0):
        list[n] = n*fact(n-1)
    return list[n]
 
t = int(sys.stdin.readline())
for i in range(0,t):
    n = int(sys.stdin.readline())
    print(fact(n))


