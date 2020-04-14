'''
10800번
컬러볼
'''

import sys

n=int(sys.stdin.readline())
ball=[]
colorSum={}

for i in range(n):
    c, s=map(int,sys.stdin.readline().split())
    ball.append([s,c,i,0])

ball.sort(reverse=True)

for j in range(n):
    color=ball[j][1]
    size=ball[j][0]
    for k in range(j+1, n):
        if size>ball[k][0]:
            colorSum[ball[k][1]]+=ball[k][0]
            ball[j][3]+=(ball[k][0]-colorSum[ball[j][1]])
            
        
ans={}
for l in range(n):
    ans[ball[l][2]]=ball[l][3]

for m in range(n):
    print(ans[m])