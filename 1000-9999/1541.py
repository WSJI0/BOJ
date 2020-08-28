'''
1541번
잃어버린 괄호
'''

import sys
input=sys.stdin.readline

p=input().rstrip()
s=p.split("-")
for i in range(len(s)):
    S=s[i].split("+"); res=""
    for j in range(len(S)):
        res+=S[j].lstrip("0")
        if j!=len(S)-1: res+="+"
    s[i]='('+res+')'

print(eval('-'.join(s)))