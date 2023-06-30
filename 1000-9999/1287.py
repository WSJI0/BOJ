pre=input()
new=''
check=''
if pre.count('()')!=0: 
    print("ROCK")
    exit(0)

tmp=[]; cur=""
for i in pre:
    if i in ['+', '-', '*', '/', '(', ')']:
        if cur!="": tmp.append(cur)
        tmp.append(i)
        cur=""
    else: cur+=i
if cur!="": tmp.append(cur)

for i in tmp:
    if i not in ['+', '-', '*', '/', '(', ')']:
       check+=str(int(i))
    else: 
        if i in ['+', '-', '*', '/']: check+="&"

try: eval(check)
except:
    print("ROCK")
    exit(0)

s=[]
for i in range(len(tmp)):
    if tmp[i]=='(': s.append(['(', i, False])
    elif tmp[i]==')':
        if len(s)>0 and s[-1][0]=='(' and s[-1][2]==True:
            s.pop()
        else: s.append([')', i, False])
    else:
        if len(s)>0 and s[-1][0]=='(':
            s[-1][2]=True

final=""
cnt=0
for i in range(len(s)):
    if s[i][0]=='(': cnt+=1
    else: cnt-=1
    if cnt<0: break
    tmp[s[i][1]]="E"
if cnt!=0:
    print("ROCK")
    exit(0)

for i in tmp:
    if i=="E": pass
    elif i=="/": final+="//"
    elif i in ['+', '-', '*', '/', '(', ')']: final+=i
    else: final+=str(int(i))

try:
    print(eval(final))
except Exception as e:
    print("ROCK")