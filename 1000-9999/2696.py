'''
2696번
중앙값
'''

import sys
import heapq
input=sys.stdin.readline

class priorityQueue():
    def __init__(self):
        self.queue=[]
        self.cnt=0
    def push(self, v, p):
        self.cnt+=1
        heapq.heappush(self.queue, (v, self.cnt, p))
    def pop(self):
        heapq.heappop(self.queue)
    def value(self):
        return self.queue
    def size(self):
        return len(self.queue)


t=int(input())
for _ in range(t):
    m=int(input())
    a=list(map(int, input().split()))
    
    pq=priorityQueue()
    for i in range(m):
        pq.push(str(a[i]),a[i])
        if i%2==0:
            print(pq.value())
    