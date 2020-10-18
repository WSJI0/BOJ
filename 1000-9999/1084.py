'''
1084번
방 번호 2
'''

import sys
input=sys.stdin.readline

for n in sys.stdin:
    c=list(map(int, input().split()))
    cost={}; ans=''
    for i in range(len(c)):
        cost[i]=c[i]
    
    print(ans[:min(50, len(ans))])
    print(ans[-min(50, len(ans)):])