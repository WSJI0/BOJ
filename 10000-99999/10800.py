'''
10800번
컬러볼
'''

import sys

n=int(sys.stdin.readline())
ball=[]
ans=[0]*n
color=[0]*(n+1)

for i in range(n):
    c, s=map(int,sys.stdin.readline().split())
    ball.append([s, c, 0, i])

ball.sort(reverse=True)
for i in range(n-1, -1, -1):
    ball[i][2]=color[ball[i][1]]+ball[i][0]
    ans[ball[i][3]]=sum(color)-color[ball[i][1]]
    color[ball[i][1]]=ball[i][2]

for i in ans: print(i)