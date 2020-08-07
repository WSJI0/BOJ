'''
19541번
역학 조사
'''

import sys
input=sys.stdin.readline

n, m=map(int, input().split())

info=[]
for _ in range(m):
    info.append(list(map(int, input().split()))[1:])
ans=[0]+list(map(int, input().split()))

for i in range(m-1, -1, -1):
    for j in info[i]:
        if ans[j]!=ans[0]:
            res="NO"

if res=="NO":
    print(res)
else:
    print("YES")
    print(*ans[1:])