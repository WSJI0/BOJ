'''
1016번
제곱 ㄴㄴ 수
'''

import sys

a,b=map(int,sys.stdin.readline().split())
ans=[0]*(b-a+1)
po=[]
end=int(b**0.5)
result=0

for i in range(2, end+1):
    po.append(i**2)

for j in po:
    k=int(((a//b)+1)*j)-a
    while k<=b-a:
        ans[k]=1
        k+=j

print(ans.count(0))