'''
2292번
벌집
'''

n=int(input())-2

if n==-1:
    print(1)
else:
    m=n//6
    i=0
    while ((i+2)*(i-1))/2<m:
        i+=1
    print(i+1)
