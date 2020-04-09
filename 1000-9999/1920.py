'''
1920번
수 찾기
'''

n=int(input())
N=list(map(int,input().split()))
N.sort()

m=int(input())
M=list(map(int,input().split()))

def biSearch(e, target):
    left=0
    right=len(target)-1
    while left<=right:
        mid=(left+right)//2
        if target[mid]>e:
            right=mid-1
        elif target[mid]<e:
            left=mid+1
        else:
            return 1
            break
    return 0   

for i in M:
    if biSearch(i,N):
        print(1)
    else:
        print(0)