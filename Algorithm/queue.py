'''
큐

add - 큐에 값을 추가(enqueue)
delete - 큐의 front값을 제거(dequeue)
data - 큐의 값을 return
size - 큐의 크기(length)를 return
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