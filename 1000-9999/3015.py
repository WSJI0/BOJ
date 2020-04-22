'''
3015번
오아시스 재결합
'''

import sys

n=int(sys.stdin.readline())

stack=[]
result=0

for _ in range(n):
    h=int(sys.stdin.readline())

    while len(stack)!=0:
        if stack[-1][0]>=h:
            break
        else:
            result+=stack[-1][1]
            stack.pop()
    
    if len(stack)==0:
        stack.append([h,1])
    else:
        if stack[-1][0]==h:
            tem=stack[-1]
            stack.pop()
            result+=tem[1]
            if len(stack)!=0:
                result+=1
            tem[1]+=1
            stack.append(tem)
        else:
            stack.append([h,1])
            result+=1
print(result)