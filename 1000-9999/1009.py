'''
1009번
분산처리
'''

testCase=int(input())
for i in range(testCase):
    a,b=map(int,input().split())

    o0=[0,0,0,0]
    o1=[1,1,1,1]
    o2=[2,4,8,6]
    o3=[3,9,7,1]
    o4=[4,6,4,6]
    o5=[5,5,5,5]
    o6=[6,6,6,6]
    o7=[7,9,3,1]
    o8=[8,4,2,6]
    o9=[9,1,9,1]

    oa="o"+str(a%10)
    exec("oar="+str(oa)+"["+str(b%4-1)+"]")
    if(oar==0):
        print("10")
    else:
        print(oar)
