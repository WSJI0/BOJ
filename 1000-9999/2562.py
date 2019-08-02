'''
2562번
최댓값
'''

li=[]

for i in range(9):
    a=int(input())
    li.append(a)
print(max(li))
print(li.index(max(li))+1)
