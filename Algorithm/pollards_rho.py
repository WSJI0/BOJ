#Wikipedia

from itertools import count
from math import gcd

number=int(input())
x=2
for cycle in count(1):
    y=x
    for i in range(pow(2, cycle)):
        x=(x*x+1)%number
        factor=gcd(x-y, number)
        if factor>1:
            while number%factor==0:
                print(factor)
                number//=factor
            if number==1: exit()