'''
1110번
더하기 사이클
'''

cycle=0
oldn=0

def f(n):
    global oldn,cycle
    
    if int(n)==0:
        cycle+=1
    elif int(n)<10:
        d=str(n)+"0"
        f(d)
    else:
        oldn=n
        while(1):
            a=int(n[0])
            b=int(n[1])

            if a+b<10:
                n=str(b)+str(a+b)
            else:
                n=str(b)+str((a+b)%10)
            cycle+=1
            if oldn==n:
                break

inp=input()
f(inp)
print(cycle)
