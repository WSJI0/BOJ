'''
1422번
숫자의 신
'''

import sys
input=sys.stdin.readline

def sort2(a):
    for i in range(len(a)-1):
        idx=i
        for j in range(i+1, len(a)):
            if int(a[j]+a[idx])>int(a[idx]+a[j]):
                idx=j
        a[idx], a[i]=a[i], a[idx]

k, n=map(int, input().split())
a=[]; mNum=0
for _ in range(k):
    a.append(input().rstrip())
    if mNum<int(a[-1]):
        mNum=int(a[-1])
    
for _ in range(n-k): a.append(str(mNum))
sort2(a)
print(''.join(a))