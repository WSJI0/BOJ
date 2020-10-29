'''
1090번
체커
'''

import sys
input=sys.stdin.readline

n=int(input())
coor=[]
for _ in range(n): 
    coor.append(list(map(int, input().split())))

def roundn(n):
    if (n%1)>=0.5: return int(n)+1
    else: return int(n)

ans=99999999999999999999999999
sel=[]
def choose(i):
    global ans, sel, n
    if i==0:
        aX=0; aY=0; res=0
        for j in sel: aX+=coor[j][0]; aY+=coor[j][1]
        aX=roundn(aX/len(sel)); aY=roundn(aY/len(sel))
        for j in sel:
            res+=abs(aX-coor[j][0])+abs(aY-coor[j][1])
        ans=min(ans, res)
        return
    for j in range(sel[-1]+1, n):
        sel.append(j)
        choose(i-1)
        sel.pop()

for i in range(1, n+1):
    for j in range(n):
        sel.append(j)
        choose(i-1)
        sel.pop()
    print(ans, end=' ')
    ans=999999999999999999999999999
print()