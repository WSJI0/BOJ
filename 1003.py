'''
1003번
피보나치
'''

p0=0
p1=0
arr=[1,0,1,1]

for n in range(4,45):
    arr.append((arr[n-2]+arr[n-1]))

testCase=int(input())
for i in range(testCase):
    num=int(input())
    p0=arr[num]
    p1=arr[num+1]

    print(str(p0)+" "+str(p1))
    p0=0
    p1=0
