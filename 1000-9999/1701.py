'''
1701번
Cubeditor

시간초과
'''

word=input()

def count2(w):
    global word
    allCount=0
    for i in range(len(word)-len(w)+1):
        if word[i:i+len(w)]==w:
            allCount+=1
    return allCount

maxN=0
for i in range(len(word)):
    for j in range(min(len(word)-i,len(word))):
        if word[i:j]!="":
            if count2(word[i:j])>1:
                if len(word[i:j])>maxN:
                    maxN=len(word[i:j])
        
print(maxN)