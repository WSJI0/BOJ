'''
2869번
달팽이는 올라가고 싶다
'''

import math

a,b,v=map(int,input().split())

print(math.ceil((v-a)/(a-b))+1)
