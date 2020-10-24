'''
1112번
진법 변환

미완성
'''

import sys
input=sys.stdin.readline

x, b=map(int, input().split())
ans=0
for i in range(len(str(x))):
    j=len(str(x))-i-1
    ans+=pow(b, j)*int(str(x)[i])

print(ans)