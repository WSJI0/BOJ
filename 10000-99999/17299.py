'''
17299번
오등큰수
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))

cnt={}
s=[]
for i in range(n):
    if a[i] not in cnt: cnt[a[i]]=0
    cnt[a[i]]+=1

ans=[-1]*n
s.append([a[0], 0])
for i in range(1, n):
    while s and cnt[s[-1][0]]<cnt[a[i]]:
        ans[s.pop()[1]]=a[i]
    s.append([a[i], i])

print(*ans)