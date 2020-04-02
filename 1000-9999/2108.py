'''
2108번
통계학
'''

import sys
from collections import Counter

n=int(input())

num=[]

for _ in range(n):
    N=int(sys.stdin.readline())
    num.append(N)
num.sort()
co=Counter(num).most_common(2)

print(round(sum(num)/n))
print(num[n//2])

if len(co)>1:
    if co[0][1]==co[1][1]:
        print(co[1][0])
    else:
        print(co[0][0])
else:
    print(co[0][0])

print(num[len(num)-1]-num[0])