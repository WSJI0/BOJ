'''
2164번
카드2
'''

n=int(input())
card=list(range(2,n+1,2))

while len(card)!=1:
    if len(card)%2==1:
        t=card[1::2]
        t.insert(0,card[-1])
        card=t
    else:
        card=card[1::2]

if n==1:
    print(1)
else:
    print(card[0])