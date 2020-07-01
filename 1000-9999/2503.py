'''
2503번
숫자 야구
'''

import sys

n=int(sys.stdin.readline())

ans=[]
for i in range(111, 1000):
    I=str(i)
    if I[0]==I[1] or I[1]==I[2] or I[0]==I[2] or '0' in I:
        continue
    ans.append(I)

no=set()
for i in range(n):
    num, strike, ball=sys.stdin.readline().split()
    for j in ans:
        st=0
        ba=0
        if j[0]==num[0]: st+=1
        if j[1]==num[1]: st+=1
        if j[2]==num[2]: st+=1
        if j[0]==num[1] or j[0]==num[2]: ba+=1
        if j[1]==num[0] or j[1]==num[2]: ba+=1
        if j[2]==num[0] or j[2]==num[1]: ba+=1

        if strike!=str(st) or ball!=str(ba): no.add(int(j))

print(len(ans)-len(no))