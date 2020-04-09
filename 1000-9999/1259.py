'''
1259번
팰린드롬수
'''

while True:
    word=list(input())
    
    if word==['0']:
        break

    if word==list(reversed(word)):
        print("yes")
    else:
        print("no")