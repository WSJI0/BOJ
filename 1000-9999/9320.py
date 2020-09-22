'''
9320번
금고 열기
'''

import sys
input=sys.stdin.readline

yes=False
def check(p, res):
    global yes
    if sum(p)==0:
        if res==24: yes=True
        return 
    for i in range(4):
        if p[i]==0: continue
        tmp=p[i]
        p[i]=0
        check(p, res+tmp)
        check(p, res-tmp)
        check(p, tmp-res)
        check(p, res*tmp)
        if tmp!=0: check(p, res//tmp)
        if res!=0: check(p, tmp//res)
        p[i]=tmp

n=int(input())
for _ in range(n):
    p=list(map(int, input().split()))
    check(p, 0)
    if yes: print("YES"); yes=False
    else: print("NO")