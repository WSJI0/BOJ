'''
PriorityQueue 우선순위 큐
'''

import heapq

class priorityQueue():
    def __init__(self):
        self.queue=[]
        self.cnt=0
    def push(self, v, p):
        self.cnt+=1
        heapq.heappush(self.queue, (p, self.cnt, v))
    def pop(self):
        heapq.heappop(self.queue)
    def value(self):
        return self.queue
    def size(self):
        return len(self.queue)

pq=priorityQueue()
pq.push('three', 3)
print(pq.value())
pq.push('six', 6)
print(pq.value())
pq.push('five', 5)
print(pq.value())
pq.push('one', 1)
print(pq.value())
pq.push('four', 4)
print(pq.value())
pq.push('two', 2)
print(pq.value())