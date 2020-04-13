'''
11000번
강의실 배정
'''

import sys

class Queue:
    def __init__(self):
        self.queue=[]
    
    def add(self, n):
        self.queue.append(n)
    
    def delete(self):
        if self.queue!=[]:
            self.queue.pop(0)
    
    def data(self):
        return self.queue
    
    def size(self):
        return len(self.queue)

n=int(sys.stdin.readline())

time=[]
for _ in range(n):
    s,t=map(int,sys.stdin.readline().split())
    time.append([s,t])

time.sort()

q=Queue()
q.add(time[0][1])

for i in range(1, n):
    if time[i][0]<q.data()[0]:
        q.add(time[i][1])
    else:
        q.delete()
        q.add(time[i][1])

print(q.size())