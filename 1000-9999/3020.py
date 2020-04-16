'''
3020번
개똥벌레
'''

import sys

def biSearchLeft(e, target):
    left=0
    right=len(target)-1
    while left<=right:
        mid=(left+right)//2
        if target[mid]>e:
            right=mid-1
        elif target[mid]<e:
            left=mid+1
        else:
            while mid>0:
                mid-=1
                if target[mid]!=e:
                    return mid+1
            return mid
            break
    return 'no'

def biSearchRight(e, target):
    left=0
    right=len(target)-1
    while left<=right:
        mid=(left+right)//2
        if target[mid]>e:
            right=mid-1
        elif target[mid]<e:
            left=mid+1
        else:
            while mid<len(target)-1:
                mid+=1
                if target[mid]!=e:
                    return mid-1
            return mid
            break
    return 'no'

n, h=map(int, sys.stdin.readline().split())

cave=[]
for i in range(n):
    if i%2==0:
        cave.append(int(sys.stdin.readline()))
    else:
        cave.append(-int(sys.stdin.readline()))

cave.sort()

road=[0]*h
road2=[0]*h
for j in range(h):
    k=h-j
    result=biSearchLeft(k, cave)
    
    if result!='no':
        road[j]+=(n-result)
    else:
        if j!=0:
            for i in range(1, j+1):
                if road[j-i]!=0:
                    road[j]+=road[j-i]
                    break

for l in range(h):
    k=-(h-l)
    result=biSearchRight(k, cave)

    if result!='no':
        road2[l]+=result+1
    else:
        if l!=0:
            for i in range(1, l+1):
                if road2[l-i]!=0:
                    road2[l]+=road2[l-i]
                    break
road2.reverse()

root=99999999999
cnt=1

for y in range(h):
    rr=road[y]+road2[y]
    if root>rr:
        root=rr
        cnt=1
    elif root==rr:
        cnt+=1
print(root, cnt)