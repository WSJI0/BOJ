import time
import sys
from collections import deque
startTime=time.time()

a=deque()
for i in range(100000):
    a.append(i)
for i in range(100000):
    a.pop()

print("Time:", time.time()-startTime)