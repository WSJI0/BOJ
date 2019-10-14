'''
1712번
손익분기점
'''

import math

a,b,c=map(int,input().split())
if b>=c:
    print(-1)
else:
    print(math.floor(a/(c-b))+1)
