'''
7662번
이중 우선순위 큐

시간초과
'''

import sys

class MaxHeap:
    def __init__(self):
        self.heap=[]

    def __str__(self):
        return str(self.heap)

    def size(self):
        return len(self.heap)

    def data(self):
        return self.heap

    def insertElement(self, data):
        self.heap.append(data)
        if len(self.heap)>1:
            node=len(self.heap)-1
            while True:
                next_node=int(node/2)
                if self.heap[next_node]<self.heap[node]:
                    self.heap[node], self.heap[next_node]=self.heap[next_node], self.heap[node]
                else:
                    break
                node=int(node/2)
                if node==0:
                    break

    def deleteElement(self):
        root=self.heap[0]
        del self.heap[0]

        if len(self.heap)<1:
            return root
        back=self.heap[-1]
        del self.heap[-1]

        self.heap.insert(0,back)
        node=0
        next_node=0
        while True:
            node=next_node
            next_node*=2
            if next_node+3>len(self.heap):
                break
            if self.heap[next_node+1]>self.heap[next_node+2]:
                next_node+=1
            else:
                next_node+=2
            if self.heap[node]<self.heap[next_node]:
                self.heap[node], self.heap[next_node]=self.heap[next_node], self.heap[node]
        return root


class MinHeap:
    def __init__(self):
        self.heap=[]

    def __str__(self):
        return str(self.heap)

    def size(self):
        return len(self.heap)

    def data(self):
        return self.heap

    def insertElement(self, data):
        self.heap.append(data)
        if len(self.heap)>1:
            node=len(self.heap)-1
            while True:
                next_node=int(node/2)
                if self.heap[next_node]>self.heap[node]:
                    self.heap[node], self.heap[next_node]=self.heap[next_node], self.heap[node]
                else:
                    break
                node=int(node/2)
                if node==0:
                    break

    def deleteElement(self):
        root=self.heap[0]
        del self.heap[0]

        if len(self.heap)<1:
            return root
        back=self.heap[-1]
        del self.heap[-1]

        self.heap.insert(0,back)
        node=0
        next_node=0
        while True:
            node=next_node
            next_node*=2
            if next_node+3>len(self.heap):
                break
            if self.heap[next_node+1]<self.heap[next_node+2]:
                next_node+=1
            else:
                next_node+=2
            if self.heap[node]>self.heap[next_node]:
                self.heap[node], self.heap[next_node]=self.heap[next_node], self.heap[node]
        return root



testCase=int(sys.stdin.readline())

for _ in range(testCase):
    dic={}
    n=int(sys.stdin.readline())
    minHeap=MinHeap()
    maxHeap=MaxHeap()

    for _ in range(n):
        com, val=sys.stdin.readline().split()
        val=int(val)
        if com=='I':
            maxHeap.insertElement(val)
            minHeap.insertElement(val)
            dic[val]=1
        elif com=='D':
            if val==1:
                while(maxHeap.size()!=0 and dic[maxHeap.data()[0]]!=1):
                    maxHeap.deleteElement()
                if maxHeap.size()!=0:
                    dic[maxHeap.data()[0]]=0
                    maxHeap.deleteElement()
            elif val==-1:
                while(minHeap.size()!=0 and dic[minHeap.data()[0]]!=1):
                    minHeap.deleteElement()
                if minHeap.size()!=0:
                    dic[minHeap.data()[0]]=0
                    minHeap.deleteElement()
            
    if maxHeap.size()==0 or minHeap.size()==0:
        print("EMPTY")
    else:
        print(maxHeap.data()[0], minHeap.data()[0])