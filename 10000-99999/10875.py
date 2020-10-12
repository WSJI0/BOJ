'''
10875번
뱀

미완성
'''

import sys
input=sys.stdin.readline

l=int(input())
n=int(input())
a=[]
for _ in range(n):
    a.append(list(input().rstrip().split()))

visited=[]
now=[0, 0]
d='r'
change={
    'r':['u', 'd'],
    'd':['r', 'l'],
    'l':['d', 'u'],
    'u':['l', 'r']
}
ans=0
for i in range(n):
    if d=='r':
        if now[0]+a[i][0]<=l:
            col=-1
            for j in range(len(visited)):
                if 
        else:
            ans+=l-(now[0]+a[i][0])
            break
        visited.append([now[0], now[1], now[0]+a[i][0], now[1]])

    if a[i][1]=='L': d=change[d][0]
    else: d=change[d][1]