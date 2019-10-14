'''
1316번
그룹 단어 체커
'''

n=int(input())

count=0
no=0
memo=[]

for i in range(n):
    word=input()
    for i2 in range(len(word)):
        if word[i2] not in memo:
            memo.append(word[i2])
            memo.append(1)
        if i2>0:
            if word[i2]==word[i2-1]:
                memo[memo.index(word[i2])+1]+=1
    for i3 in word:
        if word.count(i3)!=memo[memo.index(i3)+1]:
            no=1
    if no==0:
        count+=1
    no=0
    memo=[]
print(count)
