'''
16638번
괄호 추가하기 2
'''

import sys
input=sys.stdin.readline

n=int(input())
pre=input().rstrip()

ans=-99999999999999999999999999
def cal(s):
    global ans
    P=pre
    op=''
    for i in range(len(s)):
        cur=''
        cur+=P[:s[i]*2-1]
        P=P[s[i]*2-1:]
        op+=str(eval(cur))
        if i!=len(s)-1: 
            op+=P[0]; P=P[1:]
    ans=max(ans, eval(op))

s=[]
def backT(i, S):
    global s
    if S==n//2+1:
        cal(s)
        return
    for j in range(1, 3):
        if S+j>n//2+1: break
        s.append(j)
        backT(j, S+j)
        s.pop()

for i in range(1, 3):
    s.append(i)
    backT(i, i)
    s.pop()

print(ans)