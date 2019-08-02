'''
3052번
나머지
'''

li=[]
co=0

for i in range(10):
    a=int(input())
    li.append(a%42)
for i2 in range(10):
    if li.count(li[i2])==1:
        co+=1
    else:
        co+=1/li.count(li[i2])
print(int(co))
