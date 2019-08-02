'''
10430
나머지
'''

a,b,c=list(map(int,input().split()))
print(str((a+b)%c)+"\n"+str((a%c+b%c)%c)+"\n"+str((a*b)%c)+"\n"+str((a%c*b%c)%c))
