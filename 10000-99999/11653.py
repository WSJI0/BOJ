'''
11653번
소인수분해
'''

import sys
input=sys.stdin.readline

n=int(input())

now=2
while n>1:
    if n%now==0:
        print(now)
        n//=now
    else:
        now+=1