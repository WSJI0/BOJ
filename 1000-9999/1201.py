'''
1201번
NMK
'''

import sys
input=sys.stdin.readline

n, m, k=map(int, input().split())

if m+k-1<=n<=m*k:
    cnt=[k]; n-=k
    for _ in range(m-1): cnt.append(n//m-1)
    idx=1
    while sum(cnt[1:])<n:
        if cnt[idx]<k: cnt[idx]+=1
        idx+=1
        if idx>=len(cnt): idx=1
    cur=0
    for i in range(len(cnt)):
        cur+=cnt[i]
        for i in range(cur, cur-cnt[i] ,-1):
            print(i, end=' ')
    print() 
else: print(-1)