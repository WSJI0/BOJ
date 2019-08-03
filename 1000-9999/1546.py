'''
1546번
평균
'''

avg=0

s=int(input())
li=list(map(int,input().split()))
m=max (li)
for i in range(len(li)):
    li[i]=(li[i]/m)*100
    avg+=li[i]/len(li)
print(avg)
