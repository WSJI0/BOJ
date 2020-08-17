'''
7894번
큰 수
'''

import sys
import math
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    m=int(input())
    print(math.ceil(math.log10(math.factorial(m))))


'''
1 2 3
4
5 6
7
8
9
10
11
12
13
14
-
15
'''