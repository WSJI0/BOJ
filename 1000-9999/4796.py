'''
4796번
캠핑
'''

import sys
input=sys.stdin.readline

case=1
while True:
    ans=0
    l, p, v=map(int, input().split())
    if l==0 and p==0 and v==0: break

    ans+=min(v%p, l)
    ans+=v//p*l
    print("Case "+str(case)+": "+str(ans))
    case+=1