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
ans=list(map(int, input().split()))

for i in range(m):
    infect=False
    for j in info[i]:
        if ans[j-1]==1:
            infect=True
            break
    if infect:
        for j in info[i]:
            ans[j-1]=0
print(*ans)