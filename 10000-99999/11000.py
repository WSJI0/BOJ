'''
11000번
강의실 배정
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

n=int(input())

time=[]
for _ in range(n):
    s,t=map(int,input().split())
    time.append([s,t])

time.sort()

q=Queue()
q.add(time[0][1])

for i in range(1, len(time)):
    if time[i][0]>=q.data()[0]:
        q.delete()
    q.add(time[i][1])

print(q.size())