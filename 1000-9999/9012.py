'''
9012번
괄호
'''

class Stack:
    def __init__(self):
        self.stack=[]

    def add(self, data):
        self.stack.append(data)

    def delete(self):
        del self.stack[-1]
        
    def data(self):
        return self.stack


testCase=int(input())

for _ in range(testCase):
    s=Stack()
    li=list(input())
    s.add(li[0])

    result='YES'
    for i in range(1, len(li)):
        if li[i]=='(':
            s.add(li[i])
        else:
            if s.data()==[]:
                result='NO'
                break
            if s.data()[-1]=='(':
                s.delete()
            else:
                result='NO'
                break

    if s.data()!=[]:
        result='NO'
    
    print(result)