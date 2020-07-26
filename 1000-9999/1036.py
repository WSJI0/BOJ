'''
1036번
36진수

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())

num=[]
ori=[]
for _ in range(n):
    ori.append(input().rstrip())
    num.append(int(ori[-1], 36))
k=int(input())

change={}
for i in range(k):
    cnt=[]
    for y in range(26): cnt.append([0,y])
    for j in range(len(ori)):
        cnt[ord(str(ori[j])[0])-65][0]+=1
    cnt.sort(reverse=True)
    print(cnt)

