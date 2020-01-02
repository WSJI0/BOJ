'''
10870번
피보나치 수 5
'''

fiboList=[0]

def fibo(n):
    if n==1 or n==2:
        return 1
    else:
        return fibo(n-1)+fibo(n-2)

for i in range(1,21):
    fiboList.append(fibo(i))

n=int(input())
print(fiboList[n])