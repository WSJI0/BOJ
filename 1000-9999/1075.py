'''
1075번
나누기
'''

import sys

n=int(sys.stdin.readline())
k=int(sys.stdin.readline())
n=(n//100)*100

for i in range(100):
    if (n+i)%k==0:
        ans=i
        break

if ans<10:
    ans="0"+str(ans)

print(ans)