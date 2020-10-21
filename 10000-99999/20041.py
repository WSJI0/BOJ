'''
20041번
Escaping
'''

import sys
input=sys.stdin.readline

n=int(input())
police=[]
for _  in range(n):
    police.append(list(map(int, input().split())))
tX, tY=map(int, input().split())

def find(dir):
    for i in range(n):
        if dir==0: #위
            if police[i][1]<=tY: continue
            if (police[i][1]-tY)>=abs(police[i][0]-tX):
                return False
        elif dir==1: #왼쪽
            if police[i][0]>=tX: continue
            if (tX-police[i][0])>=abs(police[i][1]-tY):
                return False
        elif dir==2: #아래
            if police[i][1]>=tY: continue
            if (tY-police[i][1])>=abs(police[i][0]-tX):
                return False
        elif dir==3: #오른쪽
            if police[i][0]<=tX: continue
            if (police[i][0]-tX)>=abs(police[i][1]-tY):
                return False
    return True

ans=False
for i in range(4):
    ans|=find(i)
print("YES" if ans else "NO")