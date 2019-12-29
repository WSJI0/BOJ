'''
18247번
겨울왕국 티켓 예매
'''

testCase=int(input())

for _ in range(testCase):
    n,m=list(map(int,input().split()))
    
    if n>=12 and m>=4:
        print(m*12-(m-4))
    else:
        print(-1)