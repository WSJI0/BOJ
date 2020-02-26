'''
2231번
분해합
'''

n=int(input())

if n<19:
    if n%2==0:
        print(n//2)
    else:
        print(0)
else:
    for i in range(n-(len(str(n))*9),n):
        iSplit=map(int,list(str(i)))

        sum=0

        for i2 in iSplit:
            sum+=i2
        sum+=i
        
        if sum==n:
            print(i)
            break

        if i==n-1:
            print(0)