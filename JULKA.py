"""
AUTHOR: Akhilesh Anandh
Solution for "JULKA" (www.spoj.com/problems/JULKA)
"""

import sys
for i in range(0,10):
    total = int(sys.stdin.readline())
    dif = int(sys.stdin.readline())
    klaudia = (total+dif)/2
    natalia = (total-dif)/2
    print klaudia
    print natalia

