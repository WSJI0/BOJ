'''
2860번
종이에 숫자 쓰기
'''

import sys
input=sys.stdin.readline

n=float(input())
i=n
while n!=int(n):
    n+=i

ans=[0,0,0,0,0]

ans[4]+=(n//5); n=n%5
ans[3]+=(n//4); n=n%4
ans[2]+=(n//3); n=n%3
ans[1]+=(n//2); n=n%2
ans[0]+=n
print(*list(map(int, ans)))