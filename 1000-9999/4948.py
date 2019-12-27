'''
4948번
베르트랑 공준
'''

pN=[]

def check(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return 0
    return 1

for i2 in range(2,246912):
    if check(i2)==1:
        pN.append(i2)

while(1):
    n=int(input())
    count=0
    for i in pN:
        if n<i and n*2>=i:
            count+=1
    if n!=0:
        print(count)
    else:
        break