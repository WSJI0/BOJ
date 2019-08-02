'''
2884번
알람 시계
'''

h,m=list(map(int,input().split()))
if h==0 and m<45:
    h=24
    print(str((h*60+m-45)//60)+" "+str((h*60+m-45)%60))
else:
    print(str((h*60+m-45)//60)+" "+str((h*60+m-45)%60))
