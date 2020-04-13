'''
힙
https://blex.me/@baealex 참고함
'''


class Heap:
    def __init__(self):
        self.heap=[]

    def __str__(self):
        return str(self.heap)

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

    def deleteRoot(self):
        root=self.heap[0]
        del self.heap[0]

        if len(self.heap)<0:
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