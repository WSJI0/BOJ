'''
3009번
네 번째 점
'''

x=[]
y=[]

for _ in range(3):
    a,b=map(int,input().split())
    x.append(a)
    y.append(b)

sX=0
sY=0
for i in range(3):
    if x.count(x[i])==1:
        sX=i
    if y.count(y[i])==1:
        sY=i

print(x[sX],y[sY])


'''
축에 평행한 이라는 조건을 안 읽고 풀던 부분

x=[]
y=[]

for _ in range(3):
    a,b=map(int,input().split())
    x.append(a)
    y.append(b)

tem=0
iM=0
jM=0
for i in range(3):
    for j in range(3):
        if (x[i]**2-x[i-1]**2)+(y[j]**2-y[j-1]**2)>tem:
            tem=(x[i]**2-x[i-1]**2)+(y[j]**2-y[j-1]**2)
            iM=i
            jM=j
print(x[iM],y[jM])

'''