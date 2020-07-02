'''
1931번
회의실배정
'''

import sys
input=sys.stdin.readline

n=int(input())

time=[]
for _ in range(n):
    s, e=map(int, input().split())
    time.append([e, s])

time.sort()

room=[[0,0]]
for i in range(n):
    if room[-1][0]<=time[i][1]:
        room.append(time[i])
print(len(room)-1)