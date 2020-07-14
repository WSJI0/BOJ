'''
12015번
가장 긴 증가하는 부분 수열 2
'''

import sys

n=int(sys.stdin.readline())
a=list(map(int, sys.stdin.readline().split()))

def biSearch(e, target):
    left=0
    right=len(target)-1
    while left<=right:
        mid=(left+right)//2
        if target[mid]>e:
            right=mid-1
        elif target[mid]<e:
            left=mid+1
        else:
            return mid
            break
    return 0

lis=[]
