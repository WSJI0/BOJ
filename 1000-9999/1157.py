'''
1157번
단어 공부
'''

word=input()

countArr=[]

word=word.upper()
newWord=sorted(list(set(word)))

for i in newWord:
    countArr.append(word.count(i))

if countArr.count(list(reversed(sorted(countArr)))[0])!=1:
    print("?")
else:
    print(newWord[countArr.index(max(countArr))])
