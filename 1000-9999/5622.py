'''
5622번
다이얼
'''

n=input()

time=0

for i in n:
    if i=='Z':
        time+=10
    elif i=='1':
        time+=2
    elif i=='0':
        time+=11
    elif i<='R':
        time+=(ord(i)-56)//3
    elif i>='S':
        time+=(ord(i)-57)//3
print(time)
