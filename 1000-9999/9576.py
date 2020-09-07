'''
9576번
책 나눠주기
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    s=[]
    n, m=map(int, input().split())
    for _ in range(m):
        a,b=map(int, input().split())
        s.append([b,a])

    s.sort()
    for i in range(m):
        s[i]=[s[i][1], s[i][0]]

    book=[0]*(n+1)
    cnt=0
    for i in range(m):
        for j in range(s[i][0], s[i][1]+1):
            if not book[j]:
                book[j]=1
                cnt+=1
                break
    print(cnt)

