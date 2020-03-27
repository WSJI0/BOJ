'''
5543번
상덕 버거
'''

burger=[]
drink=[]

for _ in range(3):
    b=int(input())
    burger.append(b)

for _ in range(2):
    d=int(input())
    drink.append(d)

print(min(burger)+min(drink)-50)