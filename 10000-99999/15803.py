'''
15803번
PLAYERJINAH’S BOTTLEGROUNDS
'''

x=[]
y=[]
for i in range(3):
    a,b=list(map(int,input().split()))
    x.append(a)
    y.append(b)
if x[1]==x[0] or x[2]==x[1] or x[2]==x[0]:
    if x[1]==x[0] and x[2]==x[1] and x[2]==x[0]:
        print("WHERE IS MY CHICKEN?")
    else:
        print("WINNER WINNER CHICKEN DINNER!")
else:
    d1=(y[2]-y[1])/(x[2]-x[1])
    d2=(y[1]-y[0])/(x[1]-x[0])
    if d1==d2:
        print("WHERE IS MY CHICKEN?")
    else:
        print("WINNER WINNER CHICKEN DINNER!")
