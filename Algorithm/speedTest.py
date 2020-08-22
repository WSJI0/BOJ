import time
from memory_profiler import memory_usage
from time import sleep
import sys
startTime=time.time()

from collections import deque
input=sys.stdin.readline

n, m=map(int, input().split())
SET=deque()
for i in range(n+1):
    SET.append({i:True})

for i in range(m):
    op, a, b=map(int, input().split())
    if op==0:
        SET[a].update(SET[b])
        SET[b]=SET[a]
    elif op==1:
        if b in SET[a]:
            print("YES")
        else:
            print("NO")
def f():
    # a function that with growing
    # memory consumption
    a = [0] * 1000
    sleep(.1)
    b = a * 100
    sleep(.1)
    c = b * 100
    return a
print("MEMORY:", memory_usage(f))
print("Time:", time.time()-startTime)