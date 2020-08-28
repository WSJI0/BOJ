'''
14889번
스타트와 링크
'''

import sys
input=sys.stdin.readline

n=int(input())
score=[]
for _ in range(n):
    score.append(list(map(int, input().split())))

team=[0 for _ in range(n)]
ans=999999999999999
def solve(a, b):
    global ans, n, team, score
    if a==n//2:
        ta=[]; tb=[]
        for i in range(n):
            if team[i]==1: ta.append(i)
            else: tb.append(i)
        sa=0; sb=0
        for i in range(n//2):
            for j in range(i+1, n//2):
                sa+=score[ta[i]][ta[j]]+score[ta[j]][ta[i]]
                sb+=score[tb[i]][tb[j]]+score[tb[j]][tb[i]]
        ans=min(ans, abs(sa-sb))
        return

    for i in range(b, n):
        if team[i]==0:
            team[i]=1
            solve(a+1, i)
            team[i]=0

solve(0, 0)
print(ans)