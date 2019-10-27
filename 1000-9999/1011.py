'''
1011번
Fly me to the Alpha Centauri
'''

testCase=int(input())

for i in range(testCase):
    a,b=map(int,input().split())
    d=b-a
    k=1
    while not(k*(k-1)<d and (k+1)*k>=d):
        k+=1
    if d==(k+1)*k or d==k*k:
        print(d//k+k-1)
    else:
        print(d//k+k)
