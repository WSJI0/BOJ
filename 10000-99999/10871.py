'''
10871번
X보다 작은 수
'''

li=[]
answer=""

n,x=list(map(int,input().split()))
li=list(map(int,input().split()))
for i in range(n):
    if li[i]<x:
        answer+=str(li[i])+" "
print(answer)
