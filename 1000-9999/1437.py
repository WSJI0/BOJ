'''
1437번
수 분해
'''

import sys
input=sys.stdin.readline

n=int(input())
if n<=2: print(n)
elif n%3==0:
    print(pow(3, n//3)%10007)
elif n%3==1:
    print(pow(3, n//3-1)*4%10007)
else:
    print(pow(3, n//3)*2%10007)