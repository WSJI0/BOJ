'''
3078번
좋은 친구
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())
q=[]
for _ in range(20): q.append([])

cnt=0
for i in range(n):
    name=input().rstrip()
    l=len(name)-1
    while(len(q[l])!=0 and i-q[l][0]>k):
        q[l].pop(0)
    cnt+=len(q[l])
    q[l].append(i)

print(cnt)