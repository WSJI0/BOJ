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
        return int(self.data)

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

    def makeRootLeft(self, node, left_node):
        if self.root==None:
            self.root=node
        node.left=left_node

    def makeRootRight(self, node, right_node):
        if self.root==None:
            self.root=node
        node.right=right_node

node=[]
for _ in range(7):
    node.append(Node(input()))

m_tree=Tree()
for i in range(len(node)-1):
    if node[i]>node[i+1]:
        m_tree.makeRoot(node[i],node[i+1])
    else:
        for j in range(len(node)):
            if node[i+j]


m_tree.postorderTraversal(m_tree.root)