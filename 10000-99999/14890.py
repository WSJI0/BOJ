'''
14890번
경사로

미완성
'''

import sys
input=sys.stdin.readline

n, l=map(int, input().split())
board=[[] for _ in range(n)]
ans=0
for _ in range(n):
    b=list(map(int, input().split()))
    for ii in range(n):
        board[ii].append(b[ii])

    go=True
    bridge=0
    for i in range(n-1):
        if b[i]!=b[i+1]:
            if b[i]+1==b[i+1]:
                B=b[i]; cnt=0; I=i
                while B==b[i] and I>=0:
                    B=b[I]
                    if B!=b[i]:break
                    cnt+=1; I-=1
                #print("UP CNT:",cnt," / index:",i)
                if cnt>=l:
                    if bridge>=i-cnt:
                        go=False
                        break
                else: go=False

            elif b[i]==b[i+1]+1:
                B=b[i+1]; cnt=0; I=i+1
                while B==b[i+1] and I<n:
                    B=b[I]
                    if B!=b[i+1]:break
                    cnt+=1; I+=1
                #print("DOWN CNT:",cnt," / index:",i)
                if cnt<l: go=False
                else:
                    bridge=i+l
            else:
                go=False
                break
    if go: ans+=1; print("YES")

for y in board:
    go=True
    bridge=0
    for i in range(n-1):
        if y[i]!=y[i+1]:
            if y[i]+1==y[i+1]:
                B=y[i]; cnt=0; I=i
                while B==y[i] and I>=0:
                    B=y[I]
                    if B!=y[i]:break
                    cnt+=1; I-=1
                if cnt>=l:
                    if bridge>=I:
                        go=False
                        break
                else: go=False

            elif y[i]==y[i+1]+1:
                B=y[i+1]; cnt=0; I=i+1
                while B==y[i+1] and I<n:
                    B=y[I]
                    if B!=y[i+1]:break
                    cnt+=1; I+=1
                if cnt<l: go=False
                else:
                    bridge=i+1+l
            else:
                go=False
                break
    if go: ans+=1

print(ans)