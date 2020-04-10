'''
10816번
숫자 카드 2
'''

from sys import stdin

n=int(stdin.readline())
N=list(map(int,stdin.readline().split()))

m=int(stdin.readline())
M=list(map(int,stdin.readline().split()))


result={}

for i in N:
    if i in result:
        result[i]+=1
    else:
        result[i]=1

for j in M:
    if j in result:
        print(result[j], end=' ')
    else:
        print(0, end=' ')