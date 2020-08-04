import time
import sys
startTime=time.time()
sys.setrecursionlimit(100000000)

def nCr(n):
    res=1
    for i in range(n-2, n+1):
        res*=i
    return max(res//6, 1)

print(nCr(100))

print("Time:", time.time()-startTime)