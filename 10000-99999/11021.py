'''
11021번
A+B -7
'''

testCase=int(input())
for i in range(testCase):
    a,b=list(map(int,input().split()))
    print("Case #"+str(i+1)+": "+str(a+b))
