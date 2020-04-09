'''
1966번
프린터 큐
'''

testCase=int(input())

importance=[]
for _ in range(testCase):
    order=1
    n,m=map(int,input().split())
    k=list(map(int,input().split()))
    
    for i in range(n):
        importance.append([k[i],i])

    imNew=[]
    while(max(k)!=0):
        for j in range(len(importance)):
            if importance[j][0]==max(k):
                imNew.append(importance[j])
                del importance[j]
                importance.insert(j,[0,0])
                k[j]=0

    print(imNew)
    importance=[]