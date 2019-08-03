'''
4344번
평균은 넘겠지
'''

avg=0
p=0

testCase=int(input())
for i in range(testCase):
    li=list(map(int,input().split()))
    for i2 in range(1,len(li)):
        avg+=li[i2]
    avg=avg/(len(li)-1)
    for i3 in range(1,len(li)):
        if li[i3]>avg:
            p+=1
    print(str('%0.3f'%round(100*p/(len(li)-1),3))+"%")
    p=0
    avg=0
