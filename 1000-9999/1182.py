'''
1182번
부분수열의 합
'''

import sys

n, s=map(int, sys.stdin.readline().split())
a=list(map(int, sys.stdin.readline().split()))

S=[0]
cnt=0
for i in a:
    for j in list(S):
        S.append(i+j)
        if S[-1]==s:
            cnt+=1

print(cnt)