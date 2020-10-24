'''
5485번
평균값 수열
'''

# https://lastknight00.tistory.com/122
# Thank you lastknight00
import sys
input=sys.stdin.readline

s=[]
n=int(input())
for _ in range(n):
    s.append(int(input()))

ans=0
a=y=s[1]; x=s[0]; b=y*2-x
for i in range(2, n):
    x=y; y=s[i]
    a=y*2-a; b=max(y*2-b, y)
    a,b=b,a

ans=max(b-a+1, 0)
print(ans)