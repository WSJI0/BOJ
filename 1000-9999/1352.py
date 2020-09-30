'''
1352번
문자열

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())
ans=[0, 1]
for i in range(2, 14):
    ans.append(ans[-1]+i)

alpha='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
if n not in ans: print(-1)
else:
    idx=ans.index(n)
    ans=alpha[:idx]
    for i in range(1, idx):
        ans+=alpha[i]*i
    print(ans)