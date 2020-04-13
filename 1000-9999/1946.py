'''
1946번
신입 사원
'''

testCase=int(input())

for _ in range(testCase):
    n=int(input())

    greedy=0
    comWith=0
    score=[]
    for i in range(n):
        a,b=map(int,input().split())
        score.append([n-a,n-b])
        if greedy<(2*n)-a-b:
            comWith=i
            greedy=(2*n)-a-b

    no=0
    for j in score:
        print(j[0],j[1],"XX",score[comWith][0],score[comWith][1])
        if j[0]<score[comWith][0] and j[1]<score[comWith][1]:
            no+=1
    print(n-no)