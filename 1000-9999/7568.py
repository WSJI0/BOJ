'''
7568번
덩치
'''

n=int(input())

people=[[],[]]
xy=[]

for i in range(n):
    x,y=map(int,input().split())
    people[0].append(x)
    people[1].append(y)
    xy.append([x*y,i])

xy=sorted(xy,reverse=True)

for j in range(n):
    if people[0][xy[j]]