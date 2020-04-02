'''
2750번
수 정렬하기
'''

n=int(input())

num=[]
for _ in range(n):
    num.append(int(input()))

num.sort()
for i in num:
    print(i)