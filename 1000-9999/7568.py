'''
7568번
덩치
'''

n=int(input())

people=[[],[]]
result=[]

for i in range(n):
    x,y=map(int,input().split())
    people[0].append(x)
    people[1].append(y)


for j in range(len(people[0])):
    grade=1
    for k in range(len(people[0])):
        if people[0][j]<people[0][k] and people[1][j]<people[1][k]:
            grade+=1
    result.append(str(grade))

print(' '.join(result))


'''
5
55 185
58 183
88 186
60 175
46 155
'''