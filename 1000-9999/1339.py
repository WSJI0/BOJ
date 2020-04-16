'''
1339번
단어 수학
'''

import sys

n=int(sys.stdin.readline())

ex={'A':0,'B':0,'C':0,'D':0,'E':0,'F':0,'G':0,'H':0,'I':0,'J':0,'K':0,'L':0,'M':0,'N':0,'O':0,'P':0,'Q':0,'R':0,'S':0,'T':0,'U':0,'V':0,'W':0,'X':0,'Y':0,'Z':0}

for _ in range(n):
    w=sys.stdin.readline()
    for i in range(2, len(w)+1):
        digit=10**(len(w)-i)
        ex[w[i-2]]+=digit

sortedEx=list(sorted(ex.items(), key=lambda k: k[1], reverse=True))

sum=0
k=0
for j in range(9,0,-1):
    sum+=sortedEx[k][1]*j
    k+=1
print(sum)