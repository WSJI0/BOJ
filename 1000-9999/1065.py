'''
1065번
한수
'''

n=int(input())
hanNum=0

if n<100:
    hanNum=n
else:
    hanNum=99
    for i in range(100,n+1):
        a=int(str(i)[0])
        d=int(str(i)[1])-int(str(i)[0])
        hN=""
        for i2 in range(len(str(i))):
            hN=hN+str(a+i2*d)
        if str(i)==hN:
            hanNum+=1
print(hanNum) 
