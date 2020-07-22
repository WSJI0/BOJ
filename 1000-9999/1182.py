'''
1182번
부분수열의 합
'''

import sys
input=sys.stdin.readline

n, s=map(int, input().split())
a=list(map(int, input().split()))

su=0
ans=0
def backT(d):
    global n, s, a, su, ans
    if d==n: return
    if su+a[d]==s: ans+=1

    backT(d+1)
    su+=a[d]
    backT(d+1)
    su-=a[d]

backT(0)
print(ans)