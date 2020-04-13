'''
덱
'''


class Deque:
    def __init__(self):
        self.deque=[]
    
    def push_front(self, n):
        self.deque.append(n)
    
    def push_back(self, n):
        self.deque.insert(0,n)
    
    def pop_front(self):
        if self.deque!=[]:
            self.deque.pop()

    def pop_back(self):
        if self.deque!=[]:
            self.deque.pop(0)

    def front(self):
        return self.deque[-1]

    def back(self):
        return self.deque[0]
    
    def data(self):
        return self.deque
    
    def size(self):
        return len(self.deque)