'''
19533번
길이 문자열
'''

import sys
input=sys.stdin.readline

ans=['1', '-2', '1-3', '-2-4', '1-3-5', '-2-4-6', '1-3-5-7', '-2-4-6-8', '1-3-5-7-9', '1-3-5-7-10', '-2-4-6-8-11', '1-3-5-7-9-12', '1-3-5-7-10-13', '-2-4-6-8-11-14', '1-3-5-7-9-12-15', '1-3-5-7-10-13-16', '-2-4-6-8-11-14-17', '1-3-5-7-9-12-15-18', '1-3-5-7-10-13-16-19', '-2-4-6-8-11-14-17-20', '1-3-5-7-9-12-15-18-21']
ans2=['1-3-5-7-9-12-15-1...', '1-3-5-7-10-13-16-...', '-2-4-6-8-11-14-17...']

def modPow(a, n, l):
    if n==0: return 1
    res=modPow(a*a%l, n//2, l)
    if n&1: res=res*a%l
    return res

dp=[0]*1000015
dp[3]=1
for i in range(4, 1000015):
    now, pre=i, dp[i-1]
    dp[i]=(now-((modPow(10,now-1,now)-modPow(10,now-2,now)-pre%now)%now)+1)

t=int(input())
for _ in range(t):
    a, b=map(int, input().split())
    if b==0 or b==1:
        if (0<a<22 and b==0) or (0<a<3 and b==1):
            sys.stdout.write(str(ans[a*pow(10,b)-1])+'\n')
            continue
    l=len(str(a))+b+1
    A=a; B=10
    while b>0:
        if b&1: A*=B%l
        B=B*B%l
        b>>=1
    A=A%l

    if l==3:
        sys.stdout.write(str(ans2[a*(10**b)%3])+'\n')
    else:
        s=dp[l-1]
        start=(modPow(10, l-2, l)+s)%l
        if A%l==start:
            sys.stdout.write(str(ans2[1])+'\n')
        elif A%l==(start+1)%l:
            sys.stdout.write(str(ans2[2])+'\n')
        else:
            sys.stdout.write(str(ans2[0])+'\n')