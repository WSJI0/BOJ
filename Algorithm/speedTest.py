import time
import sys
from collections import deque
startTime=time.time()

a=0
for i in range(10000000):
    if i>=a: a=i
print(a)

print("Time:", time.time()-startTime)

startTime=time.time()

a=0
for i in range(10000000):
    a=max(a, i)
print(a)

print("Time:", time.time()-startTime)