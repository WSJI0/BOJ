'''
2096번
내려가기
'''

import sys
input=sys.stdin.readline

ans1=[]
ans2=[]
n=int(input())
for _ in range(n):
    a, b, c=map(int, input().split())
    if len(ans1)==0:
        ans1=[a,b,c]; ans2=[a,b,c]
        continue
    
    res1=[max(ans1[:2])+a, max(ans1)+b, max(ans1[1:])+c]
    res2=[min(ans2[:2])+a, min(ans2)+b, min(ans2[1:])+c]
    ans1=res1; ans2=res2

print(max(ans1), min(ans2))