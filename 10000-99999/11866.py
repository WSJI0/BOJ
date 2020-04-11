'''
11866번
요세푸스 문제 0
'''

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

import sys

n, k=map(int,sys.stdin.readline().split())

q=Queue()
result=[]

for i in range(1, n+1):
    q.add(i)

t=0
if k!=1:
    while q.size()>0:
        t+=1
        q.add(q.data()[0])
        q.delete()
        if t%(k-1)==0:
            result.append(q.data()[0])
            q.delete()
else:
    result=list(range(1,n+1))

    
print("<", end='')
for j in range(n-1):
    print(str(result[j])+",", end=' ')
print(str(result[-1])+">", end='')