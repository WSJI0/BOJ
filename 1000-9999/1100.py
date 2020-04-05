'''
1100번
하얀 칸
'''

count=0
for i in range(8):
    line=list(input())
    for j in range(0,8,2):
        if i%2==0:
            if line[j]=='F':
                count+=1
        if i%2==1:
            if line[j+1]=='F':
                count+=1
print(count)