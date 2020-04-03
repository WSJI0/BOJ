'''
1181번
단어 정렬
'''

n=int(input())

word=[]
for _ in range(n):
    w=input()
    wLen=len(w)
    if not([wLen,w] in word):
        word.append([wLen,w])

word.sort()

for i in word:
    print(i[1])