'''
9267번
A+B
'''

import sys
input=sys.stdin.readline

a, b, s=map(int, input().split())

def GCD(a, b):
    return b if a%b==0 else GCD(b, a%b)

print()