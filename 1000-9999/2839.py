'''
2839번
설탕 배달
'''

n=int(input())
num=0

while(n>0):
    if n%5==0:
        n-=5
        num+=1
    elif n%3==0:
        n-=3
        num+=1
    elif n>5:
        n-=5
        num+=1
    else:
        num=-1
        break
print(num)
