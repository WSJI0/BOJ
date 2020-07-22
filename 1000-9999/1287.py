'''
1287번
할 수 있다
'''

import sys
input=sys.stdin.readline

pre=input().rstrip()
new=''
check=''
if pre.count('()')!=0: new+='ERROR'
for i in pre:
    if i=='/': new+='//'
    else: new+=i
    if i not in ['0','1','2','3','4','5','6','7','8','9','(',')']:
        check+='&'
    else:
        check+=i

try:
    eval(check)
    print(eval(new))
except:
    print("ROCK")