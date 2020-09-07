'''
1132번
합
'''

import sys
input=sys.stdin.readline

n=int(input())
num=[]
start=[0,0,0,0,0,0,0,0,0,0]
for _ in range(n):
    a=input().rstrip()
    num.append(a)
    start[ord(a[0])-65]=1

cnt=[[0, x] for x in range(10)]
for i in range(n):
    c=1
    for j in range(len(num[i])-1, -1, -1):
        cnt[ord(num[i][j])-65][0]+=c
        c*=10
cnt.sort(reverse=True)

dic=[0,0,0,0,0,0,0,0,0,0]
for i in range(10):
    dic[9-i]=chr(cnt[i][1]+65)
    if i==9 and start[cnt[i][1]]==1:
        for j in range(1, 10):
            if start[ord(dic[j])-65]==0:
                t=dic.pop(j)
                break
        dic.insert(0, t)

s=[]
for i in range(n):
    new=[]
    for j in num[i]:
        new.append(str(dic.index(j)))
    s.append(''.join(new))

print(eval('+'.join(s)))