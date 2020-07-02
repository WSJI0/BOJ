'''
1700번
멀티탭 스케줄링
'''

import sys
input=sys.stdin.readline

n, k=map(int, input().split())
a=list(map(int, input().split()))

plug=[0]*n
cnt=0
while True:
    if len(a)==0: break

    plugged=False
    for i in range(n):
        if plug[i]==a[0]:
            a.pop(0)
            plugged=True
            break
    if not plugged:
        for i in range(n):
            if plug[i]==0:
                plug[i]=a.pop(0)
                plugged=True
                break
    if not plugged:
        plugged2=False
        for i in range(n):
            if plug[i] not in a:
                plugged2=True
                plugged=True
                cnt+=1
                plug[i]=0
                break
        if not plugged2:
            his=[]
            for i in range(n):
                if a[i] not in his:
                    his.append(a[i])
            for j in range(len(his)-1, -1, -1):
                for p in range(n):
                    if plug[p]==his[j]:
                        plug[p]=0
                        cnt+=1
                        plugged=True
                        break
                if plugged: break
    if not plugged:
        plug[0]=0
        cnt+=1

print(cnt)