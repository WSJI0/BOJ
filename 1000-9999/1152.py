'''
1152번
단어의 개수
'''

word=input()

if word!="":
    if word[len(word)-1]==" ":
        word=word[0:len(word)-1]
if word!="":
    if word[0]==" ":
        word=word[1:len(word)]

print(len(word.split()))
