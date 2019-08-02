'''
15552번
빠른 A+B
'''

import sys

testCase=int(sys.stdin.readline().rstrip())
for i in range(testCase):
    a,b=list(map(int,sys.stdin.readline().rstrip().split()))
    print(a+b)
