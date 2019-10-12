'''
2675번
문자열 반복
'''

testCase=int(input())

word=""
for i in range(testCase):
    r,s=input().split()
    for i2 in s:
        word+=i2*int(r)
    print(word)
    word=""
