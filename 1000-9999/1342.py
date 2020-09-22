'''
1342번
행운의 문자열
'''

import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**6)

s=list(input().rstrip())

def check(s):
    for i in range(len(s)-1):
        if s[i+1]==s[i]:
            return False
    return True

ans=0
visited={}

def backT(s):
    global ans
    if ''.join(s) not in visited:
        visited[''.join(s)]=True
        if check(s): ans+=1
        for i in range(len(s)):
            for j in range(i+1, len(s)):
                s[i], s[j]=s[j], s[i]
                backT(s)
                s[i], s[j]=s[j], s[i]

backT(s)
print(ans)