import time
import sys
from collections import deque
startTime=time.time()

a=deque()
for i in range(1000):
    a.append(i)
for i in range(1000):
    a.popleft()

print("Time:", time.time()-startTime)