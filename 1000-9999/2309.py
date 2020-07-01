'''
2309번
일곱 난쟁이
'''

a=[]
for i in range(9):
    a.append(int(input()))

for i in range(9):
    for j in range(i+1, 9):
        if a[i]+a[j]==sum(a)-100:
            del a[j]
            del a[i]
            break
    if len(a)==7:
        break

a.sort()
for i in range(7):
    print(a[i])