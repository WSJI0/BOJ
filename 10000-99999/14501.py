'''
14501번
퇴사

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())

c=[]
for _ in range(n):
    c.append(list(map(int, input().split())))

for i in range(n):
    if c[i][0]>n-i:
        c[i][1]=0
c.extend([[0,0],[0,0]])
dp=[0]*17
dp[0]=c[0][1]
for i in range(n, -1, -1):
    dp[i]=max(c[i+1][1], c[i][1]+c[i+c[i][0]][1])

print(dp)