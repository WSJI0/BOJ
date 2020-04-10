'''
트리

preorderTraversal 전위순회
inorderTraversal 중위순회
postorderTraversal 후위순회
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

    def connectLeft(self, node, left_node):
        if self.root==None:
            self.root=node
        node.left=left_node

    def connectRight(self, node, right_node):
        if self.root==None:
            self.root=node
        node.right=right_node