'''
1019번
책 페이지

미완성
'''

import sys
input=sys.stdin.readline

n=int(input())

N=0
for i in range(len(str(n))-1):
    N+=n//10

ans=[N]*10



'''
for i in range(1, len(str(n))+1):
    ans[int(str(n)[-i])]+=int(str(n)[-i+1])
'''
print(*ans)