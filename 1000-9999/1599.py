'''
1599번
민식어
'''

import sys

n=int(sys.stdin.readline())

word=[]
for _ in range(n):
    w=sys.stdin.readline().split("\n")[0]
    ori=w
    w=w.replace('k', 'c')
    w=w.replace('y', 'z')
    w=w.replace('w', 'y')
    w=w.replace('u', 'w')
    w=w.replace('t', 'u')
    w=w.replace('s', 't')
    w=w.replace('r', 's')
    w=w.replace('p', 'r')
    w=w.replace('o', 'p')
    w=w.replace('ng', 'o')
    word.append([w, ori])

word.sort()
for i in word:
    print(i[1])