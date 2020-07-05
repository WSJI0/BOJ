'''
5397번
키로거

미완성
'''

import sys
input=sys.stdin.readline

t=int(input())

for _ in range(t):
    word=list(input().rstrip())
    ans=[]
    cursor=0
    for i in word:
        if i=='<':
            cursor=max(0, cursor-1)
        elif i=='>':
            cursor=min(len(ans), cursor+1)
        elif i=='-':
            if len(ans)!=0:
                del ans[cursor-1]
                cursor-=1
        else:
            ans.insert(cursor, i)
            cursor+=1
    print(''.join(ans))