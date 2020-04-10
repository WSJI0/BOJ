'''
2164번
카드2
'''

n=int(input())
card=list(range(2,n+1,2))

i=0
while True:
    card.pop(i)
    if i==len(card)-1:
        i=0
    if len(card)==1:
        break
    i+=1

if n==1:
    print(1)
else:
    print(card[0])