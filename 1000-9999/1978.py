'''
1978번
소수 찾기
'''

N=int(input())
num=list(map(int,input().split()))

count=N
def check(n):
    global count
    for i2 in range(2,n):
        if n%i2==0:
            count-=1
            break

for i in num:
    if i!=1:
        check(i)
    else:
        count-=1
print(count)