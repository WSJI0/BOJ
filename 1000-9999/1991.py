'''
1991번
트리 순회
'''

import sys
input=sys.stdin.readline

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
        if node.left!=None:
            self.preorderTraversal(node.left)
        if node.right!=None:
            self.preorderTraversal(node.right)
    
    def inorderTraversal(self, node):
        if node.left!=None:
            self.inorderTraversal(node.left)
        print(node, end='')
        if node.right!=None:
            self.inorderTraversal(node.right)

    def postorderTraversal(self, node):
        if node.left!=None:
            self.postorderTraversal(node.left)
        if node.right!=None:
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


n=int(input())

tree=Tree()

node={}
alpha=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
for i in alpha:
    node[i]=Node(i)
for _ in range(n):
    a, b, c=input().rstrip().split()
    if b!='.': tree.connectLeft(node[a], node[b])
    if c!='.': tree.connectRight(node[a], node[c])

tree.preorderTraversal(tree.root)
print()
tree.inorderTraversal(tree.root)
print()
tree.postorderTraversal(tree.root)