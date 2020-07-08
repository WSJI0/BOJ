'''
5076번
Web Pages
'''

import sys
input=sys.stdin.readline

while True:
    code=input().rstrip()
    if code=='#': break
    
    stack=[]
    tag=[]
    op=-1
    result="legal"
    for i in range(len(code)):
        if code[i]=='<':
            op=i
        elif code[i]=='>' and op!=-1:
            if code[op:i+1]=="<br />": continue
            if code[op+1]=="/":
                if len(tag)!=0:
                    if tag[-1].replace('/','')==code[op:i+1]:
                        tag.pop()
                        continue
                else:
                    result="illegal"
                    break
            tag.append(code[op:i+1])
            op=-1
        print(tag)
    if len(tag)!=0:
        result="illegal"
    print(result)