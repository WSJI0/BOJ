'''
9020번
골드바흐의 추측
'''

pN=[]
eN=[]

for _ in range(10001):
    eN.append([])

def check(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return 0
    return 1

for i2 in range(2,5082):
    if check(i2)==1:
        pN.append(i2)

for i5 in range(len(pN)):
    for i6 in range(i5,len(pN)):
        if (pN[i5]+pN[i6])%2==0 and (pN[i5]+pN[i6])<=10000:
            eN[pN[i5]+pN[i6]].append([pN[i5],pN[i6]])

testCase=int(input())

for i in range(testCase):
    tem=[0,0]
    n=int(input())
    for [i3,i4] in eN[n]:
        if i3*i4>tem[0]*tem[1]:
            tem=[i3,i4]

    print(tem[0],tem[1])