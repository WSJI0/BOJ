'''
1351번
무한 수열
'''

import sys
input=sys.stdin.readline

n, p, q=map(int, input().split())
N=0

dic={0:1}

def a(idx):
    if idx in dic: return dic[idx]
    dic[idx]=a(idx//p)+a(idx//q)
    return dic[idx]

print(a(n))