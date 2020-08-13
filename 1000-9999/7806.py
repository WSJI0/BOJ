'''
7806번
GCD!
'''

import sys
input=sys.stdin.readline

while True:
    try:
        n, k=map(int, input().split())
        N=0
        for i in range(1, int(k**0.5)+1):
            if k%i==0:
                N+=1
    except: break