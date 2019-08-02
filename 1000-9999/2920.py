'''
2920번
음계
'''

li=list(map(int,input().split()))
if li==sorted(li):
    print("ascending")
elif li==sorted(li,reverse=True):
    print("descending")
else:
    print("mixed")
