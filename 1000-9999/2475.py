'''
2475번
검증수
'''

squareMap=[0,1,4,9,6,5,6,9,4,1]

n=list(map(int,input().split()))

sum=0
for i in n:
    sum+=squareMap[i]

print(sum%10)