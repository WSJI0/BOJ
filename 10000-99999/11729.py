'''
11729번
하노이 탑 이동 순서
'''

n=int(input())

print(2**n-1)

def solveHanoi(d,s,e,w=2): #disc start end waypoint
    if d==1:
        print(s,e)
        return 0
    
    solveHanoi(d-1,s,w,e)
    print(s,e)
    solveHanoi(d-1,w,e,s)

solveHanoi(n,1,3)
