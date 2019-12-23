'''
10250번
ACM 호텔
'''

testCase=int(input())
for i in range(testCase):
    h,w,n=list(map(int,input().split()))
    if n%h==0:
        print((n//h)+(100*h))
    else:
        print((n%h)*100+(n//h)+1)
