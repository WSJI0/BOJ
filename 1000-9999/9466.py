'''
9466번
텀 프로젝트
'''

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n=int(input())
    a=[0]+list(map(int, input().split()))

    cnt=0
    visited={}
    team=0
    for i in range(1, n+1):
        NEXT=i
        team+=1
        if NEXT not in visited:
            while NEXT not in visited:
                visited[NEXT]=team
                NEXT=a[NEXT]
            while NEXT in visited and visited[NEXT]==team:
                visited[NEXT]=0
                NEXT=a[NEXT]

    print(n-list(visited.values()).count(0))