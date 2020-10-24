'''
12972번
GCD 테이블
'''

import sys
from collections import Counter
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
c=Counter(a)

def GCD(a, b):
    if b==0: return a
    return b if a%b==0 else GCD(b, a%b)

ans=[]
for _ in range(n):
    cur=max(c); c[cur]-=1
    for i in ans:
        c[GCD(cur, i)]-=2
    ans.append(cur)
    c+=Counter()

print(*ans)