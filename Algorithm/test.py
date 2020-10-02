import sys
input=sys.stdin.readline

x1, y1, x2, y2=map(int, input().split())
x3, y3, x4, y4=map(int, input().split())

s1=0 if y1==y2 else (x2-x1)/(y2-y1)
s2=0 if y3==y4 else (x4-x3)/(y4-y3)

if s2!=s1:
    x=(s2*x3-s1*x1-y3+y1)/(s2-s1)
    print(1 if (min(x1, x2)<=x<=max(x1, x2) and min(x3, x4)<=x<=max(x3, x4)) else 0)
elif s1==0 and s2==0:
    res=False
    res|=min(x1, x2)<=x3<=max(x1, x2) and min(y1, y2)<=y3<=max(y1, y2)
    res|=min(x1, x2)<=x4<=max(x1, x2) and min(y1, y2)<=y4<=max(y1, y2)
    print(1 if res else 0)
else:
    res1=False
    res1|=(min(y3, y4)<=y1<=max(y3, y4) and s2*(x1-x3)+y3==y1)
    res1|=(min(y3, y4)<=y2<=max(y3, y4) and s2*(x2-x3)+y3==y2)
    res2=False
    res2|=(min(y1, y2)<=y3<=max(y1, y2) and s1*(x3-x1)+y1==y3)
    res2|=(min(y1, y2)<=y4<=max(y1, y2) and s1*(x4-x1)+y1==y4)
    print(1 if res1 and res2 else 0)