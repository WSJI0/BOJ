dic={}
for i in range(2, 101):
    dic[i]=input()
for j in range(2, 101):
    if dic[j]!=input():
        print(str(j)+" is different")