'''
1007번
벡터 매칭
'''

import sys
input=sys.stdin.readline

vec=[0, 0]
def backT(i, cnt, r):
    global vec, coor, n, ans
    if cnt==1:
        for j in range(n):
            if choose[j]==0:
                choose[j]=1
                vec=[
                    vec[0]+(coor[j][0]-coor[i][0]),
                    vec[1]+(coor[j][1]-coor[i][1])
                ]
                print(i, "with", j, vec, coor[j][0], coor[i][0])
                backT(j, 2, r+1)
                choose[j]=0
    if r==n: 
        ans=min(ans, (vec[0]**2+vec[1]**2)**0.5)
        print("ANS", ans)
        return
    else: 
        for j in range(n):
            if choose[j]==0:
                choose[j]=1
                backT(j, 1, r+1)
                choose[j]=0

t=int(input())
for _ in range(t):
    n=int(input())
    ans=999999999999999999999999999999
    coor=[]
    for _ in range(n):
        coor.append(list(map(int, input().split())))
    vec=[0, 0]
    choose=[0]*n
    for i in range(n):
        choose[i]=1
        backT(i, 1, 1)
        choose[i]=0

    print("ANS : ", ans)