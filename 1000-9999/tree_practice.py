'''
5639번
이진 검색 트리
'''

class Node:
    def __init__(self, data):
        self.data=data
        self.left=None
        self.right=None

    def __str__(self):
        return str(self.data)

class Tree:
    def __init__(self):
        self.root=None

    def preorderTraversal(self, node):
        print(node, end='')
        if not node.left==None:
            self.preorderTraversal(node.left)
        if not node.right==None:
            self.preorderTraversal(node.right)
    
    def inorderTraversal(self, node):
        if not node.left==None:
            self.inorderTraversal(node.left)
        print(node, end='')
        if not node.right==None:
            self.inorderTraversal(node.right)

    def postorderTraversal(self, node):
        if not node.left==None:
            self.postorderTraversal(node.left)
        if not node.right==None:
            self.postorderTraversal(node.right)
        print(node, end='')

    def makeRoot(self, node, left_node, right_node):
        if self.root==None:
            self.root=node
        node.left=left_node
        node.right=right_node

node=[]
node.append(Node('A'))
node.append(Node('B'))
node.append(Node('C'))
node.append(Node('D'))
node.append(Node('E'))
node.append(Node('F'))
node.append(Node('G'))

m_tree=Tree()
for i in range(int(len(node)/2)):
    m_tree.makeRoot(node[i], node[i*2+1], node[i*2+2])

print("전위순회 : ", end='')
m_tree.preorderTraversal(m_tree.root)
print("\n중위순회 : ", end='')
m_tree.inorderTraversal(m_tree.root)
print("\n후위순회 : ", end='')
m_tree.postorderTraversal(m_tree.root)