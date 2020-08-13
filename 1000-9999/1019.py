'''
1019번
책 페이지

미완성
'''

import sys
input=sys.stdin.readline

n=input().rstrip()

ans=[0,0,0,0,0,0,0,0,0,0]
for i in range(len(n)-1):
    ans[int(n[i])]+=int(n[i+1:])
    for j in range(1, int(n[i])):
        ans[j]+=10**(len(n)-i-1)

for i in range(1, int(n[-1])+1):
    ans[i]+=1

print(*ans)