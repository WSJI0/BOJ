'''
8958번
OX퀴즈
'''

acc=0
score=0

testCase=int(input())
for i in range(testCase):
    p=input()
    for i2 in range(len(p)):
        if p[i2]=="O":
            acc+=1
            score+=acc
        if p[i2]=="X":
            acc=0
    print(score)
    acc=0
    score=0
