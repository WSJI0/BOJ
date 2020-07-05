'''
16434번
드래곤 앤 던전
'''

import sys
import math
input=sys.stdin.readline

N, ATK=map(int, input().split())

room=[]
for i in range(N):
    room.append(list(map(int, input().split())))

def battle(pAtk, pHp, mAtk, mHp):
    pHp-=max(0, math.ceil(mHp/pAtk)-1)*mAtk
    return pHp

l=1
r=1000000000000000000
while(l<=r):
    mid=(l+r)//2

    hp=mid
    atk=ATK
    for i in room:
        if i[0]==1:
            hp=battle(atk, hp, i[1], i[2])
        else:
            atk+=i[1]
            hp=min(hp+i[2], mid)
        if hp<1: 
            break

    if hp<1:
        l=mid+1
    else:
        ans=mid
        r=mid-1

print(ans)