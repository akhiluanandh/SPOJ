# AUTHOR: Akhilesh Anandh
# Solution to "Diagonal" (www.spoj.com/problems/DIG)

import sys
for i in range(0,int(input())):
	x = int(input())
	y = x*(x-1)*(x-2)*(x-3)
	y = (y/24)%1000000007
	print y
