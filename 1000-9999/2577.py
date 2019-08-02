'''
2577번
숫자의 개수

count()를 사용하면 편하지만 다르게 풀어보았습니다.
'''

p0,p1,p2,p3,p4,p5,p6,p7,p8,p9=0,0,0,0,0,0,0,0,0,0

a=int(input())
b=int(input())
c=int(input())
result=str(a*b*c)
for i in range(len(result)):
    exec("p"+str(result[i])+"+=1")
    
for i2 in range(10):
    print(eval("p"+str(i2)))
