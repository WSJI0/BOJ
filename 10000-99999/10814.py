'''
10814번
나이순 정렬
'''

n=int(input())

member=[]
for i in range(n):
    age, name=input().split()
    member.append([age,i,name])

member.sort()
for j in range(n):
    print(member[j][0], member[j][2])