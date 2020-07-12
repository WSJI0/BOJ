'''
1966번
프린터 큐
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n, m=map(int, input().split())
    q=list(map(int, input().split()))
    for i in range(n):
        q[i]=[q[i],i]
    
    cnt=0
    while len(q)>0:
        toPrint=True
        now=q[0][0]
        for i in q:
            if i[0]>now:
                toPrint=False
                break
        if toPrint:
            p=q.pop(0)
            cnt+=1
            if p[1]==m:
                print(cnt)
                break
        else:
            q.append(q.pop(0))