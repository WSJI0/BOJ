'''
16395번
파스칼의 삼각형

미완성
'''

import sys
input=sys.stdin.readline

dp=[[1],[1,1],[1,2,1]]

for i in range(3, n):
    dp.append(dp[i-1])