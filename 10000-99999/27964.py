n=int(input())
ing=list(input().split())

d={}
for i in ing:
    if len(i)<6: continue
    if i[-6:]=="Cheese":
        if i[:-6] not in d:
            d[i[:-6]]=1

if len(d)>=4: print("yummy")
else: print("sad")