import time
import sys
from collections import deque
startTime=time.time()

a=deque()
for i in range(1000000):
    a.append('a')
A=''.join(a)


print("Time:", time.time()-startTime)