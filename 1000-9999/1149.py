'''
1149번
RGB거리
'''

import sys
input=sys.stdin.readline

n=int(input())

pay=[]
for _ in range(n):
    pay.append(list(map(int, input().split())))

dp=[[pay[0][0]], [pay[0][1]], [pay[0][2]]]

for i in range(1, n):
    a=[[],[],[]]
    for d in range(3):
        for j in dp[d]:
            for k in range(3):
                if d==k: continue
                a[k].append(j+pay[i][k])
                a[k].sort()
                a[k]=[a[k][0]]
    dp=a

print(min(dp)[0])