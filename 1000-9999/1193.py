'''
1193번
분수찾기
'''

x=int(input())

n=-1
while not(n*(n-1)/2>=x and (n-1)*(n-2)/2<=x):
    n+=1

if n%2==1: #정방향(위->아래)

    print(str(int(x-(n-1)*(n-2)/2))+"/"+str(int(n*(n-1)/2-x+1)))
else: #역방향(아래->위)
    print(str(int(n*(n-1)/2-x+1))+"/"+str(int(x-(n-1)*(n-2)/2)))
