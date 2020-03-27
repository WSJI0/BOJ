'''
10039번
평균 점수
'''

avg=0

for _ in range(5):
    n=float(input())
    if n>=40:
        avg+=(n/5)
    else:
        avg+=8
print(int(avg))