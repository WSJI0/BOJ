'''
1145번
적어도 대부분의 배수
'''

num=list(map(int,input().split()))

n=2
while True:
    count=0
    for j in range(5):
        if n%num[j]==0:
            count+=1
    if count>2:
        print(n)
        break
    n+=1