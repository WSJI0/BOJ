'''
1655번
가운데를 말해요
'''

import sys

class Heap:
    def __init__(self):
        self.heap=[]

    def __str__(self):
        return str(self.heap)

    def data(self):
        return self.heap

    def insertElement(self, data):
        self.heap.append(data)
        if len(self.heap)>1:
            node=len(self.heap)-1
            while True:
                next_node=node//2
                if self.heap[next_node]<self.heap[node]:
                    self.heap[node], self.heap[next_node]=self.heap[next_node], self.heap[node]
                else:
                    break
                node=node//2
                if node==0:
                    break

n=int(sys.stdin.readline())

h=Heap()
for _ in range(n):
    num=int(sys.stdin.readline())
    h.insertElement(num)
    print("XX",h.data(),h.data()[len(h.data())//2])