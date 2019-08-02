'''
10818번
최소, 최대
'''

n=int(input())
li=list(map(int,input().split()))
li.sort()
print(str(li[0])+" "+str(li[n-1]))
