'''
13904번
과제
'''

import sys
input=sys.stdin.readline

n=int(input())

assign=[]
for _ in range(n):
    d, w=map(int, input().split())
    assign.append([w, d])

toDo=[0]*max(assign, key=lambda k :k[1])[1]
assign.sort(reverse=True)
for i in range(n):
    j=assign[i][1]-1
    while j>=0:
        if toDo[j]==0:
            toDo[j]=assign[i][0]
            break
        j-=1
print(sum(toDo))
