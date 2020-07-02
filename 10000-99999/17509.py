'''
17509번
And the Winner Is... Ourselves!
'''

import sys
input=sys.stdin.readline

l=[]
for _ in range(11):
    d,v=map(int, input().split())
    l.append([d,v])

l.sort()

penalty=0
time=0
for i in range(11):
    time+=l[i][0]
    penalty+=(time+l[i][1]*20)
print(penalty)