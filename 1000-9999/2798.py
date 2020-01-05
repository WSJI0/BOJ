'''
2798번
블랙잭
'''

n,m=list(map(int,input().split()))

card=list(map(int,input().split()))

maxVal=0

for i in range(n-2):
    for j in range(i+1,n-1):
        for k in range(j+1,n):
            if (card[i]+card[j]+card[k])<=m and (card[i]+card[j]+card[k])>maxVal:
                maxVal=card[i]+card[j]+card[k]
print(maxVal)