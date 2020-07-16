'''
18827번
연속합 2147483647

부분 성공
'''

import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int, input().split()))
ma=list(sorted(a))
if ma[-1]<0:
    print(max(a))
else:
    dp=[a[0]]

    for i in range(1, n):
        if dp[i-1]+a[i]>0:
            dp.append(dp[i-1]+a[i])
        else:
            dp.append(0)

    print(max(dp))